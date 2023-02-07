/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#include "AkMixerPlatform.h"

#include "AudioMixerTypes.h"
#include "CoreGlobals.h"
#include "UObject/UObjectGlobals.h"

#include "AkSettings.h"
#include "AudioMixerInputComponent.h"

#if WITH_ENGINE
#include "AudioPluginUtilities.h"
#include "OpusAudioInfo.h"
#include "VorbisAudioInfo.h"
#include "ADPCMAudioInfo.h"
#endif // WITH_ENGINE

FName FAkMixerPlatform::NAME_OGG(TEXT("OGG"));
FName FAkMixerPlatform::NAME_OPUS(TEXT("OPUS"));
FName FAkMixerPlatform::NAME_ADPCM(TEXT("ADPCM"));


FAkMixerPlatform::FAkMixerPlatform() :
	AkAudioMixerInputComponent(nullptr),
	bIsInitialized(false),
	bIsDeviceOpen(false),
	InputEvent(nullptr),
	OutputBuffer(nullptr),
	OutputBufferByteLength(0)
{
#if !WITH_EDITOR
	LoadVorbisLibraries();
#endif
}

FAkMixerPlatform::~FAkMixerPlatform()
{
	if (bIsInitialized)
	{
		TeardownHardware();
	}
}

bool FAkMixerPlatform::OnNextBuffer(uint32 NumChannels, uint32 NumSamples, float** OutBufferToFill)
{
	if (!bIsDeviceInitialized
		|| !(AudioStreamInfo.StreamState == Audio::EAudioOutputStreamState::Open
			|| AudioStreamInfo.StreamState == Audio::EAudioOutputStreamState::Running))
	{
		return false;
	}

	checkf(OutputBufferByteLength == NumChannels * NumSamples * sizeof(float), TEXT("Please ensure the Wwise \"Samples per frame\" initialization setting matches the Unreal Audio \"Callback Buffer Size\" setting for the current platform."));

	OutputBuffer = OutBufferToFill;

	ReadNextBuffer();

	return true;
}

bool FAkMixerPlatform::InitializeHardware()
{
	if (!bIsInitialized)
	{
		AkAudioMixerInputComponent = new FAudioMixerInputComponent();

		AkAudioMixerInputComponent->OnNextBuffer = FAkGlobalAudioInputDelegate::CreateRaw(this, &FAkMixerPlatform::OnNextBuffer);

		UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
		if (AkSettings != nullptr)
		{
			AkSettings->GetAudioInputEvent(InputEvent);
		}

		if (!InputEvent)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Unable to correctly initialize AkMixerPlatform. Ak Audio Event is not set."));
		}

		bIsInitialized = true;
	}

	// Must always return true Editor startup at least, since a failed
	// initialization results in a failed initialized AudioDevice, which later
	// results in a crash.
	return bIsInitialized;
}

bool FAkMixerPlatform::TeardownHardware()
{

	if (!bIsInitialized)
	{
		return true;
	}

	StopAudioStream();
	CloseAudioStream();

	if (AkAudioMixerInputComponent)
	{
		delete AkAudioMixerInputComponent;
		AkAudioMixerInputComponent = nullptr;
	}

	bIsInitialized = false;
	return true;
}

bool FAkMixerPlatform::IsInitialized() const
{
	return bIsInitialized;
}

bool FAkMixerPlatform::GetNumOutputDevices(uint32& OutNumOutputDevices)
{
	// TODO Define constant
	OutNumOutputDevices = 1;
	return true;
}

bool FAkMixerPlatform::GetOutputDeviceInfo(const uint32 InDeviceIndex, Audio::FAudioPlatformDeviceInfo& OutInfo)
{
	AkAudioFormat AudioFormat;
	AkAudioMixerInputComponent->GetChannelConfig(AudioFormat);

	OutInfo.Format = Audio::EAudioMixerStreamDataFormat::Float;
	OutInfo.Name = "Wwise Default Audio Input Device";
	OutInfo.NumChannels = AudioFormat.GetNumChannels();
	OutInfo.SampleRate = AudioFormat.uSampleRate;

	OutInfo.OutputChannelArray.SetNum(OutInfo.NumChannels);

	for (int32 ChannelNum = 0; ChannelNum < OutInfo.NumChannels; ++ChannelNum)
	{
		OutInfo.OutputChannelArray.Add(EAudioMixerChannel::Type(ChannelNum));
	}

	return true;
}
bool FAkMixerPlatform::GetDefaultOutputDeviceIndex(uint32& OutDefaultDeviceIndex) const
{
	OutDefaultDeviceIndex = AUDIO_MIXER_DEFAULT_DEVICE_INDEX;
	return true;
}

bool FAkMixerPlatform::OpenAudioStream(const Audio::FAudioMixerOpenStreamParams& Params)
{
	if (!bIsInitialized || AudioStreamInfo.StreamState != Audio::EAudioOutputStreamState::Closed)
	{
		return false;
	}

	OpenStreamParams = Params;

	AudioStreamInfo.Reset();
	AudioStreamInfo.OutputDeviceIndex = OpenStreamParams.OutputDeviceIndex;
	AudioStreamInfo.NumOutputFrames = OpenStreamParams.NumFrames;
	AudioStreamInfo.NumBuffers = OpenStreamParams.NumBuffers;
	AudioStreamInfo.AudioMixer = OpenStreamParams.AudioMixer;

	// Allow negotiating output format with the Sound Engine
	if (!GetOutputDeviceInfo(AudioStreamInfo.OutputDeviceIndex, AudioStreamInfo.DeviceInfo))
	{
		return false;
	}

	OutputBufferByteLength = OpenStreamParams.NumFrames * AudioStreamInfo.DeviceInfo.NumChannels * GetAudioStreamChannelSize();

	AudioStreamInfo.StreamState = Audio::EAudioOutputStreamState::Open;

	bool bOpenStreamError = false;

	if (!InputEvent)
	{
		UE_LOG(LogAkAudio, Error, TEXT("Unable to open audio stream. Ak Audio Event is not set."));
		bOpenStreamError = true;
	}
	else
	{
		AkPlayingID PlayingID = AkAudioMixerInputComponent->PostAssociatedAudioInputEvent(InputEvent);

		if (PlayingID == AK_INVALID_PLAYING_ID)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Unable to open audio stream. Could not post Ak Audio Event."));
			bOpenStreamError = true;
		}
	}

	if (!bOpenStreamError)
	{
		bIsDeviceOpen = true;
	}

	// Must always return true Editor startup at least, since a failed
	// initialization results in a failed initialized AudioDevice, which later
	// results in a crash.
	return true;
}

bool FAkMixerPlatform::CloseAudioStream()
{
	if (AudioStreamInfo.StreamState == Audio::EAudioOutputStreamState::Closed)
	{
		return false;
	}

	if (!StopAudioStream())
	{
		return false;
	}

	{
		FScopeLock ScopedLock(&OutputBufferMutex);

		if (this->AkAudioMixerInputComponent)
		{
			AkAudioMixerInputComponent->PostUnregisterGameObject();
		}

		OutputBuffer = nullptr;
		OutputBufferByteLength = 0;
	}

	bIsDeviceOpen = false;

	if (bIsUsingNullDevice)
	{
		StopRunningNullDevice();
	}

	AudioStreamInfo.StreamState = Audio::EAudioOutputStreamState::Closed;
	return true;
}

bool FAkMixerPlatform::StartAudioStream()
{
	if (!bIsInitialized || (AudioStreamInfo.StreamState != Audio::EAudioOutputStreamState::Open
		&& AudioStreamInfo.StreamState != Audio::EAudioOutputStreamState::Stopped))
	{
		return false;
	}

	BeginGeneratingAudio();

	if (!bIsDeviceOpen)
	{
		StartRunningNullDevice();
	}

	AudioStreamInfo.StreamState = Audio::EAudioOutputStreamState::Running;

	return true;
}

bool FAkMixerPlatform::StopAudioStream()
{
	if (AudioStreamInfo.StreamState != Audio::EAudioOutputStreamState::Stopped
		&& AudioStreamInfo.StreamState != Audio::EAudioOutputStreamState::Closed)
	{

		if (AudioStreamInfo.StreamState == Audio::EAudioOutputStreamState::Running)
		{
			StopGeneratingAudio();
		}
	}

	return true;
}

Audio::FAudioPlatformDeviceInfo FAkMixerPlatform::GetPlatformDeviceInfo() const
{
	return AudioStreamInfo.DeviceInfo;
}

void FAkMixerPlatform::SubmitBuffer(const uint8* Buffer)
{
	FScopeLock ScopedLock(&OutputBufferMutex);

	if (OutputBuffer)
	{
		for (int32 Channel = 0; Channel < AudioStreamInfo.DeviceInfo.NumChannels; Channel++)
		{
			for (int32 Frame = 0; Frame < AudioStreamInfo.NumOutputFrames; Frame++)
			{
				FMemory::Memcpy(&OutputBuffer[Channel][Frame],
					&Buffer[sizeof(float) * ((AudioStreamInfo.DeviceInfo.NumChannels * Frame) + Channel)],
					sizeof(float));
			}
		}
	}
}

#if !UE_5_0_OR_LATER
FName FAkMixerPlatform::GetRuntimeFormat(USoundWave* InSoundWave)
{
#if WITH_ENGINE
	check(InSoundWave);
#if defined(PLATFORM_PS5) && PLATFORM_PS5
	static FName NAME_ADPCM(TEXT("ADPCM"));

	if (InSoundWave->IsStreaming() && InSoundWave->IsSeekableStreaming())
	{
		return NAME_ADPCM;
	}

	checkf(false, TEXT("Please set your Unreal audio sources to Streaming and Seekable in order to play them through Wwise on the PS5"));
	return NAME_ADPCM;
#else
	if (InSoundWave->IsStreaming(nullptr))
	{
		if (InSoundWave->IsSeekableStreaming())
		{
			return NAME_ADPCM;
		}

		return NAME_OPUS;
	}
	return NAME_OGG;
#endif
#else
	checkNoEntry();
	return FName();
#endif // WITH_ENGINE
}

bool FAkMixerPlatform::HasCompressedAudioInfoClass(USoundWave* InSoundWave)
{
	return true;
}

ICompressedAudioInfo* FAkMixerPlatform::CreateCompressedAudioInfo(USoundWave* InSoundWave)
{
#if WITH_ENGINE
	check(InSoundWave);

#if defined(PLATFORM_PS5) && PLATFORM_PS5
	if (InSoundWave->IsStreaming() && InSoundWave->IsSeekableStreaming())
	{
		return new FADPCMAudioInfo();
	}

	checkf(false, TEXT("Please set your Unreal audio sources to Streaming and Seekable in order to play them through Wwise on the PS5"));
	return new FADPCMAudioInfo();
#else
	if (InSoundWave->IsStreaming())
	{
		if (InSoundWave->IsSeekableStreaming())
		{
			return new FADPCMAudioInfo();
		}

		return new FOpusAudioInfo();
	}

	if (InSoundWave->HasCompressedData(NAME_OGG))
	{
		return new FVorbisAudioInfo();
	}

	return new FADPCMAudioInfo();
#endif
#else
	checkNoEntry();
	return nullptr;
#endif // WITH_ENGINE
}
#endif

FString FAkMixerPlatform::GetDefaultDeviceName() {
	static FString DefaultName(TEXT("Wwise Audio Mixer Device."));
	return DefaultName;
}

FAudioPlatformSettings FAkMixerPlatform::GetPlatformSettings() const
{
	return FAudioPlatformSettings::GetPlatformSettings(FPlatformProperties::GetRuntimeSettingsClassName());
}
