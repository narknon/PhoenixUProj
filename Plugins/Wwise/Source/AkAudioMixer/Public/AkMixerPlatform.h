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

#pragma once

#include "AudioMixer.h"
#include "AkUEFeatures.h"

class FAudioMixerInputComponent;
class UAkAudioEvent;

class FAkMixerPlatform : public Audio::IAudioMixerPlatformInterface
{
public:
	FAkMixerPlatform();
	~FAkMixerPlatform();

#if UE_5_0_OR_LATER
	virtual FString GetPlatformApi() const override { return TEXT("AkMixerPlatform"); }
#else
	virtual Audio::EAudioMixerPlatformApi::Type GetPlatformApi() const override { return Audio::EAudioMixerPlatformApi::Other; }
#endif
	virtual bool InitializeHardware() override;
	virtual bool TeardownHardware() override;
	virtual bool IsInitialized() const override;
	virtual bool GetNumOutputDevices(uint32& OutNumOutputDevices) override;
	virtual bool GetOutputDeviceInfo(const uint32 InDeviceIndex, Audio::FAudioPlatformDeviceInfo& OutInfo) override;
	virtual bool GetDefaultOutputDeviceIndex(uint32& OutDefaultDeviceIndex) const override;
	virtual bool OpenAudioStream(const Audio::FAudioMixerOpenStreamParams& Params) override;
	virtual bool CloseAudioStream() override;
	virtual bool StartAudioStream() override;
	virtual bool StopAudioStream() override;
	virtual Audio::FAudioPlatformDeviceInfo GetPlatformDeviceInfo() const override;
	virtual void SubmitBuffer(const uint8* Buffer) override;
#if !UE_5_0_OR_LATER
	virtual FName GetRuntimeFormat(USoundWave* InSoundWave) override;
	virtual bool HasCompressedAudioInfoClass(USoundWave* InSoundWave) override;
	virtual ICompressedAudioInfo* CreateCompressedAudioInfo(USoundWave* InSoundWave) override;
#endif
	virtual bool SupportsRealtimeDecompression() const { return true; }
	virtual FString GetDefaultDeviceName() override;
	virtual FAudioPlatformSettings GetPlatformSettings() const override;

private:
	FAudioMixerInputComponent* AkAudioMixerInputComponent;
	bool bIsInitialized;
	bool bIsDeviceOpen;
	bool bIsUsingNullDevice;
	UAkAudioEvent* InputEvent;
	float** OutputBuffer;
	int OutputBufferByteLength;
	FCriticalSection OutputBufferMutex;

	bool OnNextBuffer(uint32 NumChannels, uint32 NumSamples, float** OutBufferToFill);
	int32 GetAudioStreamChannelSize() { return sizeof(float); }

	static FName NAME_OGG;
	static FName NAME_OPUS;
	static FName NAME_ADPCM;

};

