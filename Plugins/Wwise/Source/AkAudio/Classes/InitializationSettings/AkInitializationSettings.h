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

#include "Engine/EngineTypes.h"
#include "AkInclude.h"
#include "AkInitializationSettings.generated.h"

UENUM()
enum class EAkPanningRule
{
	Speakers = AkPanningRule::AkPanningRule_Speakers,
	Headphones = AkPanningRule::AkPanningRule_Headphones,
};

UENUM()
enum class EAkChannelConfigType
{
	Anonymous = AkChannelConfigType::AK_ChannelConfigType_Anonymous,
	Standard = AkChannelConfigType::AK_ChannelConfigType_Standard,
	Ambisonic = AkChannelConfigType::AK_ChannelConfigType_Ambisonic,
};

UENUM(Meta = (Bitmask))
enum class EAkChannelMask : uint32
{
	FrontLeft,
	FrontRight,
	FrontCenter,
	LowFrequency,
	BackLeft,
	BackRight,
	BackCenter = BackRight + 3,
	SideLeft,
	SideRight,

	Top,
	HeightFrontLeft,
	HeightFrontCenter,
	HeightFrontRight,
	HeightBackLeft,
	HeightBackCenter,
	HeightBackRight,
};

static_assert((1 << (uint32)EAkChannelMask::FrontLeft) == AK_SPEAKER_FRONT_LEFT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::FrontRight) == AK_SPEAKER_FRONT_RIGHT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::FrontCenter) == AK_SPEAKER_FRONT_CENTER, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::LowFrequency) == AK_SPEAKER_LOW_FREQUENCY, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::BackLeft) == AK_SPEAKER_BACK_LEFT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::BackRight) == AK_SPEAKER_BACK_RIGHT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::BackCenter) == AK_SPEAKER_BACK_CENTER, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::SideLeft) == AK_SPEAKER_SIDE_LEFT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::SideRight) == AK_SPEAKER_SIDE_RIGHT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::Top) == AK_SPEAKER_TOP, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::HeightFrontLeft) == AK_SPEAKER_HEIGHT_FRONT_LEFT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::HeightFrontCenter) == AK_SPEAKER_HEIGHT_FRONT_CENTER, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::HeightFrontRight) == AK_SPEAKER_HEIGHT_FRONT_RIGHT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::HeightBackLeft) == AK_SPEAKER_HEIGHT_BACK_LEFT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::HeightBackCenter) == AK_SPEAKER_HEIGHT_BACK_CENTER, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");
static_assert((1 << (uint32)EAkChannelMask::HeightBackRight) == AK_SPEAKER_HEIGHT_BACK_RIGHT, "Review constants defined in \"include\\AK\\SoundEngine\\Common\\AkSpeakerConfig.h\"");


UENUM()
enum class EAkCommSystem
{
	Socket = 0, // AkCommSettings::AkCommSystem_Socket,
	HTCS = 1 // AkCommSettings::AkCommSystem_HTCS,
};

#if AK_ENABLE_COMMUNICATION
static_assert((uint32)EAkCommSystem::Socket == (uint32)AkCommSettings::AkCommSystem_Socket, "Review constants defined in \"include\\AK\\Comm\\AkCommunication.h\"");
static_assert((uint32)EAkCommSystem::HTCS == (uint32)AkCommSettings::AkCommSystem_HTCS, "Review constants defined in \"include\\AK\\Comm\\AkCommunication.h\"");
#endif

struct FAkInitializationStructure
{
	FAkInitializationStructure();
	~FAkInitializationStructure();

	AkMemSettings MemSettings;
	AkStreamMgrSettings StreamManagerSettings;
	AkDeviceSettings DeviceSettings;
	AkInitSettings InitSettings;
	AkPlatformInitSettings PlatformInitSettings;
	AkMusicSettings MusicSettings;
	AkSpatialAudioInitSettings SpatialAudioInitSettings;
#ifndef AK_OPTIMIZED
	AkCommSettings CommSettings;
#endif

	void SetPluginDllPath(const FString& PlatformArchitecture);

	typedef void* (*MemoryAllocFunction)(size_t);
	typedef void(*MemoryFreeFunction)(void*, size_t);

	void SetupLLMAllocFunctions(MemoryAllocFunction alloc = nullptr, MemoryFreeFunction free = nullptr, bool UseMemTracker = true);
};


USTRUCT()
struct FAkMainOutputSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category="Ak Initialization Settings|Main Output Settings", meta = (ToolTip = "The name of a custom audio device to be used. Custom audio devices are defined in the Audio Device Shareset section of the Wwise project. Leave this empty to output normally through the default audio device."))
	FString AudioDeviceShareset;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Main Output Settings", meta = (ToolTip = "Device specific identifier, when multiple devices of the same type are possible. If only one device is possible, leave to 0."))
	uint32 DeviceID = AK_INVALID_UNIQUE_ID;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Main Output Settings", meta = (ToolTip = "Rule for 3D panning of signals routed to a stereo bus. In \"Speakers\" mode, the angle of the front loudspeakers is used. In \"Headphones\" mode, the speaker angles are superseded with constant power panning between two virtual microphones spaced 180 degrees apart."))
	EAkPanningRule PanningRule = EAkPanningRule::Speakers;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Main Output Settings", meta = (ToolTip = "A code that completes the identification of channels by uChannelMask. Anonymous: Channel mask == 0 and channels; Standard: Channels must be identified with standard defines in AkSpeakerConfigs; Ambisonic: Channel mask == 0 and channels follow standard ambisonic order."))
	EAkChannelConfigType ChannelConfigType = EAkChannelConfigType::Anonymous;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Main Output Settings", meta = (Bitmask, BitmaskEnum = EAkChannelMask, ToolTip = "A bit field, whose channel identifiers depend on AkChannelConfigType (up to 20)."))
	uint32 ChannelMask = 0;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Main Output Settings", meta = (ToolTip = "The number of channels, identified (deduced from channel mask) or anonymous (set directly)."))
	uint32 NumberOfChannels = 0;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};


USTRUCT()
struct FAkSpatialAudioSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Maximum number of portals that sound can propagate through.", ClampMin = "0", ClampMax = "8"))
	uint32 MaxSoundPropagationDepth = AK_MAX_SOUND_PROPAGATION_DEPTH;
	static_assert(AK_MAX_SOUND_PROPAGATION_DEPTH == 8, "AK_MAX_SOUND_PROPAGATION_DEPTH has changed values. Ensure that the limits of MaxSoundPropagationDepth are equally reflected.");

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Distance (in game units) that an emitter or listener has to move to trigger a recalculation of reflections/diffraction. Larger values can reduce the CPU load at the cost of reduced accuracy.", ClampMin = "0"))
	float MovementThreshold = 10.f;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "The number of primary rays used in stochastic ray casting. A larger number of rays will increase the chances of finding reflection and diffraction paths, but will result in higher CPU usage."))
	uint32 NumberOfPrimaryRays = 100;
	
	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Maximum reflection order - the number of 'bounces' in a reflection path. A higher reflection order renders more details at the expense of higher CPU usage.", ClampMin = "0", ClampMax = "4"))
	uint32 ReflectionOrder = 1;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Length of the rays that are cast inside Spatial Audio. Effectively caps the maximum length of an individual segment in a reflection or diffraction path.", ClampMin = "0"))
	float MaximumPathLength = 10000.0f;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (DisplayName = "CPU Limit Percentage", ToolTip = "Controls the maximum percentage of an audio frame used by the raytracing engine. Percentage [0, 100] of the current audio frame. A value of 0 indicates no limit on the amount of CPU used for raytracing.", ClampMin = "0", ClampMax = "100"))
	float CPULimitPercentage = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Enable computation of diffraction along reflection paths."))
	bool EnableDiffractionOnReflections = true;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Enable computation of geometric diffraction and transmission paths for all sources that have that have the \"Enable Diffraction and Transmission\" box checked in the Positioning tab of the Wwise Property Editor. This flag enables sound paths around (diffraction) and thorugh (transmission) geometry. Setting to EnableGeometricDiffractionAndTransmission to false implies that geometry is only to be used for reflection calculation. Diffraction edges must be enabled on geometry for diffraction calculation. If EnableGeometricDiffractionAndTransmission is false but a sound has \"Enable Diffraction and Transmission\" checked in the positioning tab of the authoring tool, the sound will only diffract through portals but pass through geometry as if it is not there. One would typically disable this setting if the game intends to perform its own obstruction calculation, but in the situation where geometry is still passed to spatial audio for reflection calculation."))
	bool EnableGeometricDiffractionAndTransmission = true;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "An emitter that is diffracted through a portal or around geometry will have its apparent or virtual position calculated by Wwise Spatial Audio and passed on to the sound engine."))
	bool CalcEmitterVirtualPosition = true;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Use the Wwise obstruction curve for modeling the effect of diffraction on a sound. Diffraction is only applied to sounds that have the \"Enable Diffraction and Transmission\" box checked in the Positioning tab of the Wwise Property Editor. Diffraction can also be applied using the diffraction built-in parameter, mapped to an RTPC (the built-in parameter is populated whether or not UseObstruction is checked). While the obstruction curve is a global setting for all sounds, using it to simulate diffraction is preferred over an RTPC, because it provides greater accuracy when modeling multiple diffraction paths, or a combination of diffraction and transmission paths. This is due to the fact that RTPCs can not be separately applied to individual sound paths. Only the path with the least amount of diffraction is sent to the RTPC."))
	bool UseObstruction = true;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Spatial Audio Settings", meta = (ToolTip = "Use the Wwise occlusion curve for modeling the effect of transmission loss on a sound. The transmission loss factor is applied using the occlusion curve defined in the wwise project settings. Transmission loss is only applied to sounds that have the \"Enable Diffraction and Transmission\" box checked in the Positioning tab of the Wwise Property Editor. Transmission loss can also be applied using the transmission loss built-in parameter, mapped to an RTPC (the built-in parameter is populated whether or not UseOcclusion is checked). While the occlusion curve is a global setting for all sounds, using it to simulate transmission loss is preferred over an RTPC, because it provides greater accuracy when modeling both transmission and diffraction. This is due to the fact that RTPCs can not be applied to individual sound paths, therefore any parameter mapped to a transmission loss RTPC will also affect any potential diffraction paths originating from an emitter."))
	bool UseOcclusion = true;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};


USTRUCT()
struct FAkCommunicationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Communication Settings", meta = (ToolTip = "Size of the communication pool."))
	uint32 PoolSize = 256 * 1024;

	enum { DefaultDiscoveryBroadcastPort = 24024, };
	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Communication Settings", meta = (ToolTip = "The port where the authoring application broadcasts \"Game Discovery\" requests to discover games running on the network. Default value: 24024. (Cannot be set to 0)."))
	uint16 DiscoveryBroadcastPort = DefaultDiscoveryBroadcastPort;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Communication Settings", meta = (ToolTip = "The \"command\" channel port. Set to 0 to request a dynamic/ephemeral port."))
	uint16 CommandPort = 0;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Communication Settings", meta = (ToolTip = "The \"notification\" channel port. Set to 0 to request a dynamic/ephemeral port."))
	uint16 NotificationPort = 0;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings|Communication Settings", meta = (ToolTip = "The name used to identify this game within the authoring application. Leave empty to use FApp::GetProjectName()."))
	FString NetworkName;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;

protected:
	FString GetCommsNetworkName() const;
};


USTRUCT()
struct FAkCommunicationSettingsWithSystemInitialization : public FAkCommunicationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(Config, Category = "Ak Initialization Settings|Communication Settings", EditAnywhere, meta = (ToolTip = "Indicates whether the communication system should be initialized. Some consoles have critical requirements for initialization of their communications system. Set to false only if your game already uses sockets before sound engine initialization."))
	bool InitializeSystemComms = true;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};

USTRUCT()
struct FAkCommunicationSettingsWithCommSelection : public FAkCommunicationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(Config, Category = "Ak Initialization Settings|Communication Settings", EditAnywhere, meta = (ToolTip = "Select between Socket and HTCS communication protocol. Socket is the Default option."))
	EAkCommSystem CommunicationSystem = EAkCommSystem::Socket;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};


USTRUCT()
struct FAkCommonInitializationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Maximum number of memory pools. A memory pool is required for each loaded bank."))
	uint32 MaximumNumberOfMemoryPools = 256;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Maximum number of automation paths for positioning sounds."))
	uint32 MaximumNumberOfPositioningPaths = 255;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Size of the command queue."))
	uint32 CommandQueueSize = 256 * 1024;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Number of samples per audio frame (256, 512, 1024, or 2048)."))
	uint32 SamplesPerFrame = 1024;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Platform-independent initialization settings of output devices."))
	FAkMainOutputSettings MainOutputSettings;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Multiplication factor for all streaming look-ahead heuristic values.", ClampMin = "0.0", ClampMax = "1.0"))
	float StreamingLookAheadRatio = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Number of refill buffers in voice buffer. Set to 2 for double-buffered, defaults to 4."))
	uint16 NumberOfRefillsInVoice = 4;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings")
	FAkSpatialAudioSettings SpatialAudioSettings;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};


USTRUCT()
struct FAkCommonInitializationSettingsWithSampleRate : public FAkCommonInitializationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(Config, EditAnywhere, Category = "Common Settings", meta = (ToolTip = "Sampling Rate. Default is 48000 Hz. Use 24000hz for low quality. Any positive reasonable sample rate is supported; however, be careful setting a custom value. Using an odd or really low sample rate may cause the sound engine to malfunction."))
	uint32 SampleRate = 48000;
};


USTRUCT()
struct FAkAdvancedInitializationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Size of memory pool for I/O (for automatic streams). It is passed directly to AK::MemoryMgr::CreatePool(), after having been rounded down to a multiple of uGranularity."))
	uint32 IO_MemorySize = 2 * 1024 * 1024;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "I/O requests granularity (typical bytes/request)."))
	uint32 IO_Granularity = 32 * 1024;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Targeted automatic stream buffer length (ms). When a stream reaches that buffering, it stops being scheduled for I/O except if the scheduler is idle."))
	float TargetAutoStreamBufferLength = 380.0f;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "If true the device attempts to reuse IO buffers that have already been streamed from disk. This is particularly useful when streaming small looping sounds. The drawback is a small CPU hit when allocating memory, and a slightly larger memory footprint in the StreamManager pool."))
	bool UseStreamCache = false;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Maximum number of bytes that can be \"pinned\" using AK::SoundEngine::PinEventInStreamCache() or AK::IAkStreamMgr::PinFileInCache()."))
	uint32 MaximumPinnedBytesInCache = (uint32)-1;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Set to true to enable AK::SoundEngine::PrepareGameSync usage."))
	bool EnableGameSyncPreparation = false;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Number of quanta ahead when continuous containers should instantiate a new voice before which next sounds should start playing. This look-ahead time allows I/O to occur, and is especially useful to reduce the latency of continuous containers with trigger rate or sample-accurate transitions."))
	uint32 ContinuousPlaybackLookAhead = 1;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Size of the monitoring queue pool. This parameter is not used in Release build."))
	uint32 MonitorQueuePoolSize = 1024 * 1024;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Amount of time to wait for hardware devices to trigger an audio interrupt. If there is no interrupt after that time, the sound engine will revert to silent mode and continue operating until the hardware finally comes back."))
	uint32 MaximumHardwareTimeoutMs = 1000;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Debug setting: Enable checks for out-of-range (and NAN) floats in the processing code. Do not enable in any normal usage, this setting uses a lot of CPU. Will print error messages in the log if invalid values are found at various point in the pipeline. Contact AK Support with the new error messages for more information."))
	bool DebugOutOfRangeCheckEnabled = false;

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (EditCondition = "DebugOutOfRangeCheckEnabled", ToolTip = "Debug setting: Only used when Debug Out Of Range Check Enabled is true. This defines the maximum values samples can have. Normal audio must be contained within +1/-1. This limit should be set higher to allow temporary or short excursions out of range. Default is 16."))
	float DebugOutOfRangeLimit = 16.f;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};

USTRUCT()
struct FAkAdvancedInitializationSettingsWithMultiCoreRendering : public FAkAdvancedInitializationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Ak Initialization Settings", meta = (ToolTip = "Allow to distribute SoundEngine processing tasks across multiple threads. Requires Editor restart."))
	bool EnableMultiCoreRendering = false;

	void FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const;
};

class IAkUnrealIOHook;

namespace FAkSoundEngineInitialization
{
	bool Initialize(IAkUnrealIOHook* IOHook);
	void Finalize();
}
