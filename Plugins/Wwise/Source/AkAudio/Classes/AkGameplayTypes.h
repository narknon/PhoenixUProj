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

/*=============================================================================
	AkGameplayStatics.h:
=============================================================================*/
#pragma once

#include "Platforms/AkUEPlatform.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/LatentActionManager.h"
#include "HAL/ThreadSafeBool.h"
#include "LatentActions.h"
#include "AkGameplayTypes.generated.h"

UENUM(BlueprintType)
enum class PanningRule : uint8
{
	PanningRule_Speakers = 0,	///< Left and right positioned 60 degrees apart (by default - see AK::SoundEngine::GetSpeakerAngles()).
	PanningRule_Headphones = 1		///< Left and right positioned 180 degrees apart.
};

UENUM(BlueprintType)
enum class AkAcousticPortalState : uint8
{
	Closed = 0,
	Open = 1,
};

UENUM(BlueprintType)
enum class AkChannelConfiguration : uint8
{
	Ak_Parent = 0,
	Ak_MainMix,
	Ak_Passthrough,
	Ak_LFE,
	AK_Audio_Objects,
	Ak_1_0,
	Ak_2_0,
	Ak_2_1,
	Ak_3_0,
	Ak_3_1,
	Ak_4_0,
	Ak_4_1,
	Ak_5_0,
	Ak_5_1,
	Ak_7_1,
	Ak_5_1_2,
	Ak_7_1_2,
	Ak_7_1_4,
	Ak_Auro_9_1,
	Ak_Auro_10_1,
	Ak_Auro_11_1,
	Ak_Auro_13_1,
	Ak_Ambisonics_1st_order,
	Ak_Ambisonics_2nd_order,
	Ak_Ambisonics_3rd_order,
	Ak_Ambisonics_4th_order,
	Ak_Ambisonics_5th_order
};

UENUM(meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class AkSpeakerConfiguration
{
	Ak_Speaker_Front_Left = AK_SPEAKER_FRONT_LEFT,
	Ak_Speaker_Front_Right = AK_SPEAKER_FRONT_RIGHT,
	Ak_Speaker_Front_Center = AK_SPEAKER_FRONT_CENTER,
	Ak_Speaker_Low_Frequency = AK_SPEAKER_LOW_FREQUENCY,
	Ak_Speaker_Back_Left = AK_SPEAKER_BACK_LEFT,
	Ak_Speaker_Back_Right = AK_SPEAKER_BACK_RIGHT,
	Ak_Speaker_Back_Center = AK_SPEAKER_BACK_CENTER,
	Ak_Speaker_Side_Left = AK_SPEAKER_SIDE_LEFT,
	Ak_Speaker_Side_Right = AK_SPEAKER_SIDE_RIGHT,
	Ak_Speaker_Top = AK_SPEAKER_TOP,
	Ak_Speaker_Height_Front_Left = AK_SPEAKER_HEIGHT_FRONT_LEFT,
	Ak_Speaker_Height_Front_Center = AK_SPEAKER_HEIGHT_FRONT_CENTER,
	Ak_Speaker_Height_Front_Right = AK_SPEAKER_HEIGHT_FRONT_RIGHT,
	Ak_Speaker_Height_Back_Left = AK_SPEAKER_HEIGHT_BACK_LEFT,
	Ak_Speaker_Height_Back_Center = AK_SPEAKER_HEIGHT_BACK_CENTER,
	Ak_Speaker_Height_Back_Right = AK_SPEAKER_HEIGHT_BACK_RIGHT,
};

UENUM(BlueprintType)
enum class AkMultiPositionType : uint8
{
    SingleSource = 0, //AK::SoundEngine::MultiPositionType_SingleSource,
    MultiSources = 1, //AK::SoundEngine::MultiPositionType_MultiSources,
    MultiDirections = 2, //AK::SoundEngine::MultiPositionType_MultiDirections,
};

static_assert(static_cast<AK::SoundEngine::MultiPositionType>(AkMultiPositionType::SingleSource) == AK::SoundEngine::MultiPositionType_SingleSource, "AkMultiPositionType::SingleSource does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AK::SoundEngine::MultiPositionType>(AkMultiPositionType::MultiSources) == AK::SoundEngine::MultiPositionType_MultiSources, "AkMultiPositionType::MultiSources does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AK::SoundEngine::MultiPositionType>(AkMultiPositionType::MultiDirections) == AK::SoundEngine::MultiPositionType_MultiDirections, "AkMultiPositionType::MultiDirections does not correspond with its internal Wwise counterpart.");

UENUM(BlueprintType)
enum class AkActionOnEventType : uint8
{
	// AK::SoundEngine::AkActionOnEventType_Stop
	Stop = 0,
	// AK::SoundEngine::AkActionOnEventType_Pause
	Pause = 1,
	// AK::SoundEngine::AkActionOnEventType_Resume
	Resume = 2,
	// AK::SoundEngine::AkActionOnEventType_Break
	Break = 3,
	// AK::SoundEngine::AkActionOnEventType_ReleaseEnvelope
	ReleaseEnvelope = 4
};

static_assert(static_cast<AK::SoundEngine::AkActionOnEventType>(AkActionOnEventType::Stop) == AK::SoundEngine::AkActionOnEventType_Stop, "AkActionOnEventType::Stop does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AK::SoundEngine::AkActionOnEventType>(AkActionOnEventType::Pause) == AK::SoundEngine::AkActionOnEventType_Pause, "AkActionOnEventType::Pause does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AK::SoundEngine::AkActionOnEventType>(AkActionOnEventType::Resume) == AK::SoundEngine::AkActionOnEventType_Resume, "AkActionOnEventType::Resume does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AK::SoundEngine::AkActionOnEventType>(AkActionOnEventType::Break) == AK::SoundEngine::AkActionOnEventType_Break, "AkActionOnEventType::Break does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AK::SoundEngine::AkActionOnEventType>(AkActionOnEventType::ReleaseEnvelope) == AK::SoundEngine::AkActionOnEventType_ReleaseEnvelope, "AkActionOnEventType::ReleaseEnvelope does not correspond with its internal Wwise counterpart.");

UENUM(BlueprintType)
enum class EAkCurveInterpolation : uint8
{
	// Log3
	Log3 = 0,
	// Sine
	Sine = 1,
	// Log1
	Log1 = 2,
	// Inversed S Curve
	InvSCurve = 3,
	// Linear (Default)
	Linear = 4,
	// S Curve
	SCurve = 5,
	// Exp1
	Exp1 = 6,
	// Reciprocal of sine curve
	SineRecip = 7,
	// Exp3
	Exp3 = 8,
	// Update this value to reflect last curve available for fades
	LastFadeCurve = 8,
	// Constant ( not valid for fading values )
	Constant = 9
};

static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Log3) == AkCurveInterpolation_Log3, "AkCurveInterpolation::Log3 does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Sine) == AkCurveInterpolation_Sine, "AkCurveInterpolation::Sine does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Log1) == AkCurveInterpolation_Log1, "AkCurveInterpolation::Log1 does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::InvSCurve) == AkCurveInterpolation_InvSCurve, "AkCurveInterpolation::InvSCurve does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Linear) == AkCurveInterpolation_Linear, "AkCurveInterpolation::Linear does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::SCurve) == AkCurveInterpolation_SCurve, "AkCurveInterpolation::SCurve does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Exp1) == AkCurveInterpolation_Exp1, "AkCurveInterpolation::Exp1 does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::SineRecip) == AkCurveInterpolation_SineRecip, "AkCurveInterpolation::SineRecip does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Exp3) == AkCurveInterpolation_Exp3, "AkCurveInterpolation::Exp3 does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::LastFadeCurve) == AkCurveInterpolation_LastFadeCurve, "AkCurveInterpolation::LastFadeCurve does not correspond with its internal Wwise counterpart.");
static_assert(static_cast<AkCurveInterpolation>(EAkCurveInterpolation::Constant) == AkCurveInterpolation_Constant, "AkCurveInterpolation::Constant does not correspond with its internal Wwise counterpart.");

static_assert(AK_NotImplemented == 0, "AK_NotImplemented is not equal to 0, please change the value in the EAkResult enum");
UENUM(BlueprintType)
enum class EAkResult : uint8
{
	// Need to set hard-coded 0, or else UHT complains.
	NotImplemented				= 0				 UMETA("This feature is not implemented."),
	Success = AK_Success						 UMETA("The operation was successful."),
	Fail = AK_Fail						 UMETA("The operation failed."),
	PartialSuccess = AK_PartialSuccess				 UMETA("The operation succeeded partially."),
	NotCompatible = AK_NotCompatible				 UMETA("Incompatible formats"),
	AlreadyConnected = AK_AlreadyConnected			 UMETA("The stream is already connected to another node."),
	InvalidFile = AK_InvalidFile					 UMETA("An unexpected value causes the file to be invalid."),
	AudioFileHeaderTooLarge = AK_AudioFileHeaderTooLarge		 UMETA("The file header is too large."),
	MaxReached = AK_MaxReached					 UMETA("The maximum was reached."),
	InvalidID = AK_InvalidID					 UMETA("The ID is invalid."),
	IDNotFound = AK_IDNotFound					 UMETA("The ID was not found."),
	InvalidInstanceID = AK_InvalidInstanceID			 UMETA("The InstanceID is invalid."),
	NoMoreData = AK_NoMoreData					 UMETA("No more data is available from the source."),
	InvalidStateGroup = AK_InvalidStateGroup			 UMETA("The StateGroup is not a valid channel."),
	ChildAlreadyHasAParent = AK_ChildAlreadyHasAParent		 UMETA("The child already has a parent."),
	InvalidLanguage = AK_InvalidLanguage				 UMETA("The language is invalid (applies to the Low-Level I/O)."),
	CannotAddItseflAsAChild = AK_CannotAddItseflAsAChild		 UMETA("It is not possible to add itself as its own child."),
	InvalidParameter = AK_InvalidParameter			 UMETA("Something is not within bounds."),
	ElementAlreadyInList = AK_ElementAlreadyInList		 UMETA("The item could not be added because it was already in the list."),
	PathNotFound = AK_PathNotFound				 UMETA("This path is not known."),
	PathNoVertices = AK_PathNoVertices				 UMETA("Stuff in vertices before trying to start it"),
	PathNotRunning = AK_PathNotRunning				 UMETA("Only a running path can be paused."),
	PathNotPaused = AK_PathNotPaused				 UMETA("Only a paused path can be resumed."),
	PathNodeAlreadyInList = AK_PathNodeAlreadyInList		 UMETA("This path is already there."),
	PathNodeNotInList = AK_PathNodeNotInList			 UMETA("This path is not there."),
	DataNeeded = AK_DataNeeded					 UMETA("The consumer needs more."),
	NoDataNeeded = AK_NoDataNeeded				 UMETA("The consumer does not need more."),
	DataReady = AK_DataReady					 UMETA("The provider has available data."),
	NoDataReady = AK_NoDataReady					 UMETA("The provider does not have available data."),
	InsufficientMemory = AK_InsufficientMemory			 UMETA("Memory error."),
	Cancelled = AK_Cancelled					 UMETA("The requested action was cancelled (not an error)."),
	UnknownBankID = AK_UnknownBankID				 UMETA("Trying to load a bank using an ID which is not defined."),
	BankReadError = AK_BankReadError				 UMETA("Error while reading a bank."),
	InvalidSwitchType = AK_InvalidSwitchType			 UMETA("Invalid switch type (used with the switch container)"),
	FormatNotReady = AK_FormatNotReady				 UMETA("Source format not known yet."),
	WrongBankVersion = AK_WrongBankVersion			 UMETA("The bank version is not compatible with the current bank reader."),
	FileNotFound = AK_FileNotFound				 UMETA("File not found."),
	DeviceNotReady = AK_DeviceNotReady				 UMETA("IO device not ready (may be because the tray is open)"),
	BankAlreadyLoaded = AK_BankAlreadyLoaded			 UMETA("The bank load failed because the bank is already loaded."),
	RenderedFX = AK_RenderedFX					 UMETA("The effect on the node is rendered."),
	ProcessNeeded = AK_ProcessNeeded				 UMETA("A routine needs to be executed on some CPU."),
	ProcessDone = AK_ProcessDone					 UMETA("The executed routine has finished its execution."),
	MemManagerNotInitialized = AK_MemManagerNotInitialized	 UMETA("The memory manager should have been initialized at this point."),
	StreamMgrNotInitialized = AK_StreamMgrNotInitialized		 UMETA("The stream manager should have been initialized at this point."),
	SSEInstructionsNotSupported = AK_SSEInstructionsNotSupported	 UMETA("The machine does not support SSE instructions (required on PC)."),
	Busy = AK_Busy						 UMETA("The system is busy and could not process the request."),
	UnsupportedChannelConfig = AK_UnsupportedChannelConfig	 UMETA("Channel configuration is not supported in the current execution context."),
	PluginMediaNotAvailable = AK_PluginMediaNotAvailable		 UMETA("Plugin media is not available for effect."),
	MustBeVirtualized = AK_MustBeVirtualized			 UMETA("Sound was Not Allowed to play."),
	CommandTooLarge = AK_CommandTooLarge				 UMETA("SDK command is too large to fit in the command queue."),
	RejectedByFilter = AK_RejectedByFilter			 UMETA("A play request was rejected due to the MIDI filter parameters."),
	InvalidCustomPlatformName = AK_InvalidCustomPlatformName	 UMETA("Detecting incompatibility between Custom platform of banks and custom platform of connected application"),
	DLLCannotLoad = AK_DLLCannotLoad				 UMETA("Plugin DLL could not be loaded, either because it is not found or one dependency is missing."),
	DLLPathNotFound = AK_DLLPathNotFound				 UMETA("Plugin DLL search path could not be found."),
	NoJavaVM = AK_NoJavaVM					 UMETA("No Java VM provided in AkInitSettings."),
	OpenSLError = AK_OpenSLError					 UMETA("OpenSL returned an error.  Check error log for more details."),
	PluginNotRegistered = AK_PluginNotRegistered			 UMETA("Plugin is not registered.  Make sure to implement a AK::PluginRegistration class for it and use AK_STATIC_LINK_PLUGIN in the game binary."),
	DataAlignmentError = AK_DataAlignmentError			 UMETA("A pointer to audio data was not aligned to the platform's required alignment (check AkTypes.h in the platform-specific folder)"),
};

#define CHECK_AKRESULT_VALUE(ValueName) static_assert(AK_##ValueName == (uint32)EAkResult::ValueName, #ValueName " value has changed in AKRESULT, please update the EAkResult::" #ValueName " value");
CHECK_AKRESULT_VALUE(NotImplemented);
CHECK_AKRESULT_VALUE(Success);
CHECK_AKRESULT_VALUE(Fail);
CHECK_AKRESULT_VALUE(PartialSuccess);
CHECK_AKRESULT_VALUE(NotCompatible);
CHECK_AKRESULT_VALUE(AlreadyConnected);
CHECK_AKRESULT_VALUE(InvalidFile);
CHECK_AKRESULT_VALUE(AudioFileHeaderTooLarge);
CHECK_AKRESULT_VALUE(MaxReached);
CHECK_AKRESULT_VALUE(InvalidID);
CHECK_AKRESULT_VALUE(IDNotFound);
CHECK_AKRESULT_VALUE(InvalidInstanceID);
CHECK_AKRESULT_VALUE(NoMoreData);
CHECK_AKRESULT_VALUE(InvalidStateGroup);
CHECK_AKRESULT_VALUE(ChildAlreadyHasAParent);
CHECK_AKRESULT_VALUE(InvalidLanguage);
CHECK_AKRESULT_VALUE(CannotAddItseflAsAChild);
CHECK_AKRESULT_VALUE(InvalidParameter);
CHECK_AKRESULT_VALUE(ElementAlreadyInList);
CHECK_AKRESULT_VALUE(PathNotFound);
CHECK_AKRESULT_VALUE(PathNoVertices);
CHECK_AKRESULT_VALUE(PathNotRunning);
CHECK_AKRESULT_VALUE(PathNotPaused);
CHECK_AKRESULT_VALUE(PathNodeAlreadyInList);
CHECK_AKRESULT_VALUE(PathNodeNotInList);
CHECK_AKRESULT_VALUE(DataNeeded);
CHECK_AKRESULT_VALUE(NoDataNeeded);
CHECK_AKRESULT_VALUE(DataReady);
CHECK_AKRESULT_VALUE(NoDataReady);
CHECK_AKRESULT_VALUE(InsufficientMemory);
CHECK_AKRESULT_VALUE(Cancelled);
CHECK_AKRESULT_VALUE(UnknownBankID);
CHECK_AKRESULT_VALUE(BankReadError);
CHECK_AKRESULT_VALUE(InvalidSwitchType);
CHECK_AKRESULT_VALUE(FormatNotReady);
CHECK_AKRESULT_VALUE(WrongBankVersion);
CHECK_AKRESULT_VALUE(FileNotFound);
CHECK_AKRESULT_VALUE(DeviceNotReady);
CHECK_AKRESULT_VALUE(BankAlreadyLoaded);
CHECK_AKRESULT_VALUE(RenderedFX);
CHECK_AKRESULT_VALUE(ProcessNeeded);
CHECK_AKRESULT_VALUE(ProcessDone);
CHECK_AKRESULT_VALUE(MemManagerNotInitialized);
CHECK_AKRESULT_VALUE(StreamMgrNotInitialized);
CHECK_AKRESULT_VALUE(SSEInstructionsNotSupported);
CHECK_AKRESULT_VALUE(Busy);
CHECK_AKRESULT_VALUE(UnsupportedChannelConfig);
CHECK_AKRESULT_VALUE(PluginMediaNotAvailable);
CHECK_AKRESULT_VALUE(MustBeVirtualized);
CHECK_AKRESULT_VALUE(CommandTooLarge);
CHECK_AKRESULT_VALUE(RejectedByFilter);
CHECK_AKRESULT_VALUE(InvalidCustomPlatformName);
CHECK_AKRESULT_VALUE(DLLCannotLoad);
CHECK_AKRESULT_VALUE(DLLPathNotFound);
CHECK_AKRESULT_VALUE(NoJavaVM);
CHECK_AKRESULT_VALUE(OpenSLError);
CHECK_AKRESULT_VALUE(PluginNotRegistered);
CHECK_AKRESULT_VALUE(DataAlignmentError);


/*=============================================================================

Begin - Ak Callback Blueprint classes and structures. Known limitations:
- AkDynamicSequenceItemCallbackInfo is not exposed because Dynamic sequences are not part of this integration
- AkSpeakerVolumeMatrixCallbackInfo cannot be exposed to Blueprint because it has to be executed in the audio thread
- AkMusicPlaylistCallbackInfo cannot be exposed to Blueprint because it has to be executed in the audio thread

=============================================================================*/

/// Type of callback. Used as a bitfield in methods AK::SoundEngine::PostEvent() and AK::SoundEngine::DynamicSequence::Open().
UENUM(BlueprintType, meta = (Bitmask))
enum class EAkCallbackType : uint8
{
	EndOfEvent = 0			UMETA(ToolTip = "Callback triggered when reaching the end of an event. AkCallbackInfo can be cast to AkEventCallbackInfo."),
	Marker = 2				UMETA(ToolTip = "Callback triggered when encountering a marker during playback. AkCallbackInfo can be cast to AkMarkerCallbackInfo."),
	Duration = 3			UMETA(ToolTip = "Callback triggered when the duration of the sound is known by the sound engine. AkCallbackInfo can be cast to AkDurationCallbackInfo."),

	Starvation = 5			UMETA(ToolTip = "Callback triggered when playback skips a frame due to stream starvation. AkCallbackInfo can be cast to AkEventCallbackInfo."),
	
	MusicPlayStarted = 7	UMETA(ToolTip = "Callback triggered when a Play or Seek command has been executed (Seek commands are issued from AK::SoundEngine::SeekOnEvent()). Applies to objects of the Interactive-Music Hierarchy only. AkCallbackInfo can be cast to AkEventCallbackInfo."),

	MusicSyncBeat = 8		UMETA(ToolTip = "Enable notifications on Music Beat. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),
	MusicSyncBar = 9		UMETA(ToolTip = "Enable notifications on Music Bar. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),
	MusicSyncEntry = 10		UMETA(ToolTip = "Enable notifications on Music Entry Cue. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),
	MusicSyncExit = 11		UMETA(ToolTip = "Enable notifications on Music Exit Cue. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),
	MusicSyncGrid = 12		UMETA(ToolTip = "Enable notifications on Music Grid. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),
	MusicSyncUserCue = 13	UMETA(ToolTip = "Enable notifications on Music Custom Cue. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),
	MusicSyncPoint = 14		UMETA(ToolTip = "Enable notifications on Music switch transition synchronization point. AkCallbackInfo can be cast to AkMusicSyncCallbackInfo."),

	MIDIEvent = 16			UMETA(ToolTip = "Enable notifications for MIDI events. AkCallbackInfo can be cast to AkMIDIEventCallbackInfo."),
};

#define CHECK_CALLBACK_TYPE_VALUE(ValueName) static_assert(AK_##ValueName == (1 << (uint32)EAkCallbackType::ValueName), #ValueName " value has changed in AkCallbackType, please update the EAkCallbackType::" #ValueName " value");
CHECK_CALLBACK_TYPE_VALUE(EndOfEvent);
CHECK_CALLBACK_TYPE_VALUE(Marker);
CHECK_CALLBACK_TYPE_VALUE(Duration);
CHECK_CALLBACK_TYPE_VALUE(Starvation);
CHECK_CALLBACK_TYPE_VALUE(MusicPlayStarted);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncBeat);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncBar);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncEntry);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncExit);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncGrid);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncUserCue);
CHECK_CALLBACK_TYPE_VALUE(MusicSyncPoint);
CHECK_CALLBACK_TYPE_VALUE(MIDIEvent);

static_assert(AK::SoundEngine::Query::RTPCValue_Default == 0, "AK::SoundEngine::Query::RTPCValue_Default is not equal to 0, please change the value in the ERTPCValueType enum");
UENUM(BlueprintType)
enum class ERTPCValueType : uint8
{
	// Need to set hard-coded 0, or else UHT complains.
	Default = 0,		///< The value is the Default RTPC.
	Global = AK::SoundEngine::Query::RTPCValue_Global,		///< The value is the Global RTPC.
	GameObject = AK::SoundEngine::Query::RTPCValue_GameObject,	///< The value is the game object specific RTPC.
	PlayingID = AK::SoundEngine::Query::RTPCValue_PlayingID,	///< The value is the playing ID specific RTPC.
	Unavailable = AK::SoundEngine::Query::RTPCValue_Unavailable	///< The value is not available for the RTPC specified.
};

class AkCallbackTypeHelpers
{
public:
	static UAkCallbackInfo* GetBlueprintableCallbackInfo(EAkCallbackType CallbackType, AkCallbackInfo* CallbackInfo);
	static AkCallbackInfo* CopyWwiseCallbackInfo(AkCallbackType CallbackType, AkCallbackInfo* SourceCallbackInfo);
	static AkCallbackType GetCallbackMaskFromBlueprintMask(int32 CallbackMask);
	static EAkCallbackType GetBlueprintCallbackTypeFromAkCallbackType(AkCallbackType CallbackType);
};

/// Callback information structure used as base for all notifications handled by \ref AkCallbackFunc.
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - \ref soundengine_events
UCLASS(BlueprintType)
class AKAUDIO_API UAkCallbackInfo : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	static UAkCallbackInfo* Create(AkGameObjectID GameObjectID);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo")
	class UAkComponent * AkComponent = nullptr;

	virtual void Reset();
};

USTRUCT(BlueprintType)
struct FAkChannelMask
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Channel Mask", BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = AkSpeakerConfiguration))
	int32 ChannelMask;
};

USTRUCT(BlueprintType)
struct FAkOutputSettings
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Output Settings", BlueprintReadWrite)
	FString AudioDeviceSharesetName;

	UPROPERTY(EditAnywhere, Category = "Output Settings", BlueprintReadWrite)
	int32 IdDevice;

	UPROPERTY(EditAnywhere, Category = "Output Settings", BlueprintReadWrite, meta=(DisplayName="PanningRule"))
	PanningRule PanRule;

	UPROPERTY(EditAnywhere, Category = "Output Settings", BlueprintReadWrite)
	AkChannelConfiguration ChannelConfig;
};

/// Callback information structure corresponding to \ref AK_EndOfEvent, \ref AK_MusicPlayStarted and \ref AK_Starvation.
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - \ref soundengine_events
UCLASS(BlueprintType)
class AKAUDIO_API UAkEventCallbackInfo : public UAkCallbackInfo
{
	GENERATED_UCLASS_BODY()
public:
	static UAkEventCallbackInfo* Create(AkEventCallbackInfo* AkEventCallbackInfo);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|AkEvent")
	int32 PlayingID = 0;		///< Playing ID of Event, returned by PostEvent()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|AkEvent")
	int32 EventID = 0;		///< Unique ID of Event, passed to PostEvent()
};



// List of MIDI event types
static_assert(AK_MIDI_EVENT_TYPE_INVALID == 0, "AK_MIDI_EVENT_TYPE_INVALID is not equal to 0, please change the value in the EAkMidiEventType enum");
UENUM(BlueprintType)
enum class EAkMidiEventType : uint8
{
	// Need to set hard-coded 0, or else UHT complains.
	AkMidiEventTypeInvalid = 0,
	AkMidiEventTypeNoteOff = AK_MIDI_EVENT_TYPE_NOTE_OFF,
	AkMidiEventTypeNoteOn = AK_MIDI_EVENT_TYPE_NOTE_ON,
	AkMidiEventTypeNoteAftertouch = AK_MIDI_EVENT_TYPE_NOTE_AFTERTOUCH,
	AkMidiEventTypeController = AK_MIDI_EVENT_TYPE_CONTROLLER,
	AkMidiEventTypeProgramChange = AK_MIDI_EVENT_TYPE_PROGRAM_CHANGE,
	AkMidiEventTypeChannelAftertouch = AK_MIDI_EVENT_TYPE_CHANNEL_AFTERTOUCH,
	AkMidiEventTypePitchBend = AK_MIDI_EVENT_TYPE_PITCH_BEND,
	AkMidiEventTypeSysex = AK_MIDI_EVENT_TYPE_SYSEX,
	AkMidiEventTypeEscape = AK_MIDI_EVENT_TYPE_ESCAPE,
	AkMidiEventTypeMeta = AK_MIDI_EVENT_TYPE_META,
};

// List of Continuous Controller (cc) values
static_assert(AK_MIDI_CC_BANK_SELECT_COARSE == 0, "AK_MIDI_CC_BANK_SELECT_COARSE is not equal to 0, please change the value in the EAkMidiCcValues enum");
UENUM(BlueprintType)
enum class EAkMidiCcValues : uint8
{
	// Need to set hard-coded 0, or else UHT complains.
	AkMidiCcBankSelectCoarse = 0,
	AkMidiCcModWheelCoarse = AK_MIDI_CC_MOD_WHEEL_COARSE,
	AkMidiCcBreathCtrlCoarse = AK_MIDI_CC_BREATH_CTRL_COARSE,
	AkMidiCcCtrl3Coarse = AK_MIDI_CC_CTRL_3_COARSE,
	AkMidiCcFootPedalCoarse = AK_MIDI_CC_FOOT_PEDAL_COARSE,
	AkMidiCcPortamentoCoarse = AK_MIDI_CC_PORTAMENTO_COARSE,
	AkMidiCcDataEntryCoarse = AK_MIDI_CC_DATA_ENTRY_COARSE,
	AkMidiCcVolumeCoarse = AK_MIDI_CC_VOLUME_COARSE,
	AkMidiCcBalanceCoarse = AK_MIDI_CC_BALANCE_COARSE,
	AkMidiCcCtrl9Coarse = AK_MIDI_CC_CTRL_9_COARSE,
	AkMidiCcPanPositionCoarse = AK_MIDI_CC_PAN_POSITION_COARSE,
	AkMidiCcExpressionCoarse = AK_MIDI_CC_EXPRESSION_COARSE,
	AkMidiCcEffectCtrl1Coarse = AK_MIDI_CC_EFFECT_CTRL_1_COARSE,
	AkMidiCcEffectCtrl2Coarse = AK_MIDI_CC_EFFECT_CTRL_2_COARSE,
	AkMidiCcCtrl14Coarse = AK_MIDI_CC_CTRL_14_COARSE,
	AkMidiCcCtrl15Coarse = AK_MIDI_CC_CTRL_15_COARSE,
	AkMidiCcGenSlider1 = AK_MIDI_CC_GEN_SLIDER_1,
	AkMidiCcGenSlider2 = AK_MIDI_CC_GEN_SLIDER_2,
	AkMidiCcGenSlider3 = AK_MIDI_CC_GEN_SLIDER_3,
	AkMidiCcGenSlider4 = AK_MIDI_CC_GEN_SLIDER_4,
	AkMidiCcCtrl20Coarse = AK_MIDI_CC_CTRL_20_COARSE,
	AkMidiCcCtrl21Coarse = AK_MIDI_CC_CTRL_21_COARSE,
	AkMidiCcCtrl22Coarse = AK_MIDI_CC_CTRL_22_COARSE,
	AkMidiCcCtrl23Coarse = AK_MIDI_CC_CTRL_23_COARSE,
	AkMidiCcCtrl24Coarse = AK_MIDI_CC_CTRL_24_COARSE,
	AkMidiCcCtrl25Coarse = AK_MIDI_CC_CTRL_25_COARSE,
	AkMidiCcCtrl26Coarse = AK_MIDI_CC_CTRL_26_COARSE,
	AkMidiCcCtrl27Coarse = AK_MIDI_CC_CTRL_27_COARSE,
	AkMidiCcCtrl28Coarse = AK_MIDI_CC_CTRL_28_COARSE,
	AkMidiCcCtrl29Coarse = AK_MIDI_CC_CTRL_29_COARSE,
	AkMidiCcCtrl30Coarse = AK_MIDI_CC_CTRL_30_COARSE,
	AkMidiCcCtrl31Coarse = AK_MIDI_CC_CTRL_31_COARSE,
	AkMidiCcBankSelectFine = AK_MIDI_CC_BANK_SELECT_FINE,
	AkMidiCcModWheelFine = AK_MIDI_CC_MOD_WHEEL_FINE,
	AkMidiCcBreathCtrlFine = AK_MIDI_CC_BREATH_CTRL_FINE,
	AkMidiCcCtrl3Fine = AK_MIDI_CC_CTRL_3_FINE,
	AkMidiCcFootPedalFine = AK_MIDI_CC_FOOT_PEDAL_FINE,
	AkMidiCcPortamentoFine = AK_MIDI_CC_PORTAMENTO_FINE,
	AkMidiCcDataEntryFine = AK_MIDI_CC_DATA_ENTRY_FINE,
	AkMidiCcVolumeFine = AK_MIDI_CC_VOLUME_FINE,
	AkMidiCcBalanceFine = AK_MIDI_CC_BALANCE_FINE,
	AkMidiCcCtrl9Fine = AK_MIDI_CC_CTRL_9_FINE,
	AkMidiCcPanPositionFine = AK_MIDI_CC_PAN_POSITION_FINE,
	AkMidiCcExpressionFine = AK_MIDI_CC_EXPRESSION_FINE,
	AkMidiCcEffectCtrl1Fine = AK_MIDI_CC_EFFECT_CTRL_1_FINE,
	AkMidiCcEffectCtrl2Fine = AK_MIDI_CC_EFFECT_CTRL_2_FINE,
	AkMidiCcCtrl14Fine = AK_MIDI_CC_CTRL_14_FINE,
	AkMidiCcCtrl15Fine = AK_MIDI_CC_CTRL_15_FINE,

	AkMidiCcCtrl20Fine = AK_MIDI_CC_CTRL_20_FINE,
	AkMidiCcCtrl21Fine = AK_MIDI_CC_CTRL_21_FINE,
	AkMidiCcCtrl22Fine = AK_MIDI_CC_CTRL_22_FINE,
	AkMidiCcCtrl23Fine = AK_MIDI_CC_CTRL_23_FINE,
	AkMidiCcCtrl24Fine = AK_MIDI_CC_CTRL_24_FINE,
	AkMidiCcCtrl25Fine = AK_MIDI_CC_CTRL_25_FINE,
	AkMidiCcCtrl26Fine = AK_MIDI_CC_CTRL_26_FINE,
	AkMidiCcCtrl27Fine = AK_MIDI_CC_CTRL_27_FINE,
	AkMidiCcCtrl28Fine = AK_MIDI_CC_CTRL_28_FINE,
	AkMidiCcCtrl29Fine = AK_MIDI_CC_CTRL_29_FINE,
	AkMidiCcCtrl30Fine = AK_MIDI_CC_CTRL_30_FINE,
	AkMidiCcCtrl31Fine = AK_MIDI_CC_CTRL_31_FINE,

	AkMidiCcHoldPedal = AK_MIDI_CC_HOLD_PEDAL,
	AkMidiCcPortamentoOnOff = AK_MIDI_CC_PORTAMENTO_ON_OFF,
	AkMidiCcSustenutoPedal = AK_MIDI_CC_SUSTENUTO_PEDAL,
	AkMidiCcSoftPedal = AK_MIDI_CC_SOFT_PEDAL,
	AkMidiCcLegatoPedal = AK_MIDI_CC_LEGATO_PEDAL,
	AkMidiCcHoldPedal2 = AK_MIDI_CC_HOLD_PEDAL_2,

	AkMidiCcSoundVariation = AK_MIDI_CC_SOUND_VARIATION,
	AkMidiCcSoundTimbre = AK_MIDI_CC_SOUND_TIMBRE,
	AkMidiCcSoundReleaseTime = AK_MIDI_CC_SOUND_RELEASE_TIME,
	AkMidiCcSoundAttackTime = AK_MIDI_CC_SOUND_ATTACK_TIME,
	AkMidiCcSoundBrightness = AK_MIDI_CC_SOUND_BRIGHTNESS,
	AkMidiCcSoundCtrl6 = AK_MIDI_CC_SOUND_CTRL_6,
	AkMidiCcSoundCtrl7 = AK_MIDI_CC_SOUND_CTRL_7,
	AkMidiCcSoundCtrl8 = AK_MIDI_CC_SOUND_CTRL_8,
	AkMidiCcSoundCtrl9 = AK_MIDI_CC_SOUND_CTRL_9,
	AkMidiCcSoundCtrl10 = AK_MIDI_CC_SOUND_CTRL_10,

	AkMidiCcGeneralButton1 = AK_MIDI_CC_GENERAL_BUTTON_1,
	AkMidiCcGeneralButton2 = AK_MIDI_CC_GENERAL_BUTTON_2,
	AkMidiCcGeneralButton3 = AK_MIDI_CC_GENERAL_BUTTON_3,
	AkMidiCcGeneralButton4 = AK_MIDI_CC_GENERAL_BUTTON_4,

	AkMidiCcReverbLevel = AK_MIDI_CC_REVERB_LEVEL,
	AkMidiCcTremoloLevel = AK_MIDI_CC_TREMOLO_LEVEL,
	AkMidiCcChorusLevel = AK_MIDI_CC_CHORUS_LEVEL,
	AkMidiCcCelesteLevel = AK_MIDI_CC_CELESTE_LEVEL,
	AkMidiCcPhaserLevel = AK_MIDI_CC_PHASER_LEVEL,
	AkMidiCcDataButtonP1 = AK_MIDI_CC_DATA_BUTTON_P1,
	AkMidiCcDataButtonM1 = AK_MIDI_CC_DATA_BUTTON_M1,

	AkMidiCcNonRegisterCoarse = AK_MIDI_CC_NON_REGISTER_COARSE,
	AkMidiCcNonRegisterFine = AK_MIDI_CC_NON_REGISTER_FINE,

	AkMidiCcAllSoundOff = AK_MIDI_CC_ALL_SOUND_OFF,
	AkMidiCcAllControllersOff = AK_MIDI_CC_ALL_CONTROLLERS_OFF,
	AkMidiCcLocalKeyboard = AK_MIDI_CC_LOCAL_KEYBOARD,
	AkMidiCcAllNotesOff = AK_MIDI_CC_ALL_NOTES_OFF,
	AkMidiCcOmniModeOff = AK_MIDI_CC_OMNI_MODE_OFF,
	AkMidiCcOmniModeOn = AK_MIDI_CC_OMNI_MODE_ON,
	AkMidiCcOmniMonophonicOn = AK_MIDI_CC_OMNI_MONOPHONIC_ON,
	AkMidiCcOmniPolyphonicOn = AK_MIDI_CC_OMNI_POLYPHONIC_ON,
};

USTRUCT(BlueprintType)
struct FAkMidiEventBase
{
	GENERATED_BODY()
	FAkMidiEventBase() {}

	FAkMidiEventBase(AkMIDIEvent MIDIEvent)
		: Type((EAkMidiEventType)MIDIEvent.byType)
		, Chan(MIDIEvent.byChan)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	EAkMidiEventType	Type = EAkMidiEventType();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	uint8	Chan = 0;
};


USTRUCT(BlueprintType)
struct FAkMidiGeneric : public FAkMidiEventBase
{
	GENERATED_USTRUCT_BODY()
	
	FAkMidiGeneric() {}
	FAkMidiGeneric(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, Param1(MIDIEvent.Gen.byParam1)
		, Param2(MIDIEvent.Gen.byParam2)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|Generic")
	uint8 Param1 = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|Generic")
	uint8 Param2 = 0;
};

USTRUCT(BlueprintType)
struct FAkMidiNoteOnOff : public FAkMidiEventBase
{
	GENERATED_BODY()
	
	FAkMidiNoteOnOff() {}
	FAkMidiNoteOnOff(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, Note(MIDIEvent.NoteOnOff.byNote)
		, Velocity(MIDIEvent.NoteOnOff.byVelocity)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|NoteOnOff")
	uint8 Note = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|NoteOnOff")
	uint8 Velocity = 0;
};

USTRUCT(BlueprintType)
struct FAkMidiCc : public FAkMidiEventBase
{
	GENERATED_BODY()

	FAkMidiCc() {}
	FAkMidiCc(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, Cc((EAkMidiCcValues)MIDIEvent.Cc.byCc)
		, Value(MIDIEvent.Cc.byValue)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|CC")
	EAkMidiCcValues Cc = EAkMidiCcValues();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|CC")
	uint8 Value = 0;
};

USTRUCT(BlueprintType)
struct FAkMidiPitchBend : public FAkMidiEventBase
{
	GENERATED_BODY()

	FAkMidiPitchBend() {}
	FAkMidiPitchBend(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, ValueLsb(MIDIEvent.PitchBend.byValueLsb)
		, ValueMsb(MIDIEvent.PitchBend.byValueMsb)
		, FullValue((ValueMsb & 0x7F) << 7 | (ValueLsb & 0x7F))
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|PitchBend")
	uint8 ValueLsb = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|PitchBend")
	uint8 ValueMsb = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|PitchBend")
	int32 FullValue = 0;
};

USTRUCT(BlueprintType)
struct FAkMidiNoteAftertouch : public FAkMidiEventBase
{
	GENERATED_BODY()
		
	FAkMidiNoteAftertouch() {}
	FAkMidiNoteAftertouch(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, Note(MIDIEvent.NoteAftertouch.byNote)
		, Value(MIDIEvent.NoteAftertouch.byValue)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|NoteAfterTouch")
	uint8 Note = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|NoteAfterTouch")
	uint8 Value = 0;
};

USTRUCT(BlueprintType)
struct FAkMidiChannelAftertouch : public FAkMidiEventBase
{
	GENERATED_BODY()
	
	FAkMidiChannelAftertouch() {}
	FAkMidiChannelAftertouch(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, Value(MIDIEvent.NoteAftertouch.byValue)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|ChannelAfterTouch")
	uint8 Value = 0;
};

USTRUCT(BlueprintType)
struct FAkMidiProgramChange : public FAkMidiEventBase
{
	GENERATED_BODY()
		
	FAkMidiProgramChange() {}
	FAkMidiProgramChange(AkMIDIEvent MIDIEvent)
		: FAkMidiEventBase(MIDIEvent)
		, ProgramNum(MIDIEvent.ProgramChange.byProgramNum)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|MIDI|ProgramChange")
	uint8 ProgramNum = 0;
};

/// Callback information structure corresponding to \ref AK_MidiEvent
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - \ref soundengine_events
UCLASS(BlueprintType)
class UAkMIDIEventCallbackInfo : public UAkEventCallbackInfo
{
	GENERATED_UCLASS_BODY()
	
public:
	static UAkMIDIEventCallbackInfo* Create(AkMIDIEventCallbackInfo* akCallbackInfo);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	EAkMidiEventType GetType();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	uint8 GetChannel();

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetGeneric(FAkMidiGeneric& AsGeneric);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetNoteOn(FAkMidiNoteOnOff& AsNoteOn);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetNoteOff(FAkMidiNoteOnOff& AsNoteOff);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetCc(FAkMidiCc& AsCc);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetPitchBend(FAkMidiPitchBend& AsPitchBend);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetNoteAftertouch(FAkMidiNoteAftertouch& AsNoteAftertouch);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetChannelAftertouch(FAkMidiChannelAftertouch& AsChannelAftertouch);

	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|AkCallbackInfo|MIDI")
	bool GetProgramChange(FAkMidiProgramChange& AsProgramChange);

private:
	AkMIDIEvent AkMidiEvent;
};

/// Callback information structure corresponding to \ref AK_Marker.
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - \ref soundengine_events
/// - \ref soundengine_markers
UCLASS(BlueprintType)
class UAkMarkerCallbackInfo : public UAkEventCallbackInfo
{
	GENERATED_UCLASS_BODY()
public:
	static UAkMarkerCallbackInfo* Create(AkMarkerCallbackInfo* akCallbackInfo);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Marker")
	int32 Identifier = 0;		///< Cue point identifier

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Marker")
	int32 Position = 0;			///< Position in the cue point (unit: sample frames)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Marker")
	FString	Label;			///< Label of the marker, read from the file
};

/// Callback information structure corresponding to \ref AK_Duration.
/// \sa 
/// - AK::SoundEngine::PostEvent()
/// - \ref soundengine_events
UCLASS(BlueprintType)
class UAkDurationCallbackInfo : public UAkEventCallbackInfo
{
	GENERATED_UCLASS_BODY()
public:
	static UAkDurationCallbackInfo* Create(AkDurationCallbackInfo* akCallbackInfo);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Duration")
	float Duration = 0.f;				///< Duration of the sound (unit: milliseconds)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Duration")
	float EstimatedDuration = 0.f;		///< Estimated duration of the sound depending on source settings such as pitch. (unit: milliseconds)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Duration")
	int32 AudioNodeID = 0;			///< Audio Node ID of playing item
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Duration")
	int32 MediaID = 0;				///< Media ID of playing item. (corresponds to 'ID' attribute of 'File' element in SoundBank metadata file)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Duration")
	bool bStreaming = false;				///< True if source is streaming, false otherwise.
};

/// Structure used to query info on active playing segments.
USTRUCT(BlueprintType)
struct FAkSegmentInfo
{
	GENERATED_BODY()

	FAkSegmentInfo() {}
	FAkSegmentInfo(const AkSegmentInfo& segmentInfo)
		: CurrentPosition(segmentInfo.iCurrentPosition)
		, PreEntryDuration(segmentInfo.iPreEntryDuration)
		, ActiveDuration(segmentInfo.iActiveDuration)
		, PostExitDuration(segmentInfo.iPostExitDuration)
		, RemainingLookAheadTime(segmentInfo.iRemainingLookAheadTime)
		, BeatDuration(segmentInfo.fBeatDuration)
		, BarDuration(segmentInfo.fBarDuration)
		, GridDuration(segmentInfo.fGridDuration)
		, GridOffset(segmentInfo.fGridOffset)
	{}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	int32		CurrentPosition = 0;		///< Current position of the segment, relative to the Entry Cue, in milliseconds. Range is [-iPreEntryDuration, iActiveDuration+iPostExitDuration].

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	int32		PreEntryDuration = 0;		///< Duration of the pre-entry region of the segment, in milliseconds.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	int32		ActiveDuration = 0;		///< Duration of the active region of the segment (between the Entry and Exit Cues), in milliseconds.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	int32		PostExitDuration = 0;		///< Duration of the post-exit region of the segment, in milliseconds.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	int32		RemainingLookAheadTime = 0;///< Number of milliseconds remaining in the "looking-ahead" state of the segment, when it is silent but streamed tracks are being prefetched.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	float		BeatDuration = 0.f;			///< Beat Duration in seconds.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	float		BarDuration = 0.f;			///< Bar Duration in seconds.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	float		GridDuration = 0.f;			///< Grid duration in seconds.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|SegmentInfo")
	float		GridOffset = 0.f;			///< Grid offset in seconds.
};

UCLASS(BlueprintType)
class UAkMusicSyncCallbackInfo : public UAkCallbackInfo
{
	GENERATED_UCLASS_BODY()

public:
	static UAkMusicSyncCallbackInfo* Create(AkMusicSyncCallbackInfo* akCallbackInfo);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Music")
	int32 PlayingID = 0;		///< Playing ID of Event, returned by PostEvent()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Music")
	FAkSegmentInfo SegmentInfo;		///< Segment information corresponding to the segment triggering this callback.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Music")
	EAkCallbackType MusicSyncType = EAkCallbackType();	///< Would be either \ref AK_MusicSyncEntry, \ref AK_MusicSyncBeat, \ref AK_MusicSyncBar, \ref AK_MusicSyncExit, \ref AK_MusicSyncGrid, \ref AK_MusicSyncPoint or \ref AK_MusicSyncUserCue.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audiokinetic|AkCallbackInfo|Music")
	FString UserCueName;	///< Cue name (UTF-8 string). Set for notifications AK_MusicSyncUserCue. NULL if cue has no name.
};

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAkPostEventCallback, EAkCallbackType, CallbackType, UAkCallbackInfo*, CallbackInfo);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAkBankCallback, EAkResult, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSetCurrentAudioCultureCallback, bool, Succeeded);

struct FPendingLatentActionValidityToken
{
	bool bValid = true;
};

class FAkPendingLatentAction: public FPendingLatentAction
{
public:    
	
	// Allows objects referencing this latent action to determine if it is still valid (not deleted) before accessing it
	TSharedPtr<FPendingLatentActionValidityToken, ESPMode::ThreadSafe> ValidityToken;

	virtual void NotifyObjectDestroyed() override
	{
		// When the owning object is destroyed, the latent action is about to be deleted, so flag it as invalid
		if (ValidityToken.IsValid())
		{
			ValidityToken->bValid = false;
		}
	}
};

// Class used for Blueprint nodes blocking on EndOfEvent
class FWaitEndOfEventAction : public FAkPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink = 0;
	FWeakObjectPtr CallbackTarget;
	FThreadSafeBool EventFinished;


	FWaitEndOfEventAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, EventFinished(false)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		Response.FinishAndTriggerIf(EventFinished, ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Waiting for posted AkEvent to end.");
	}
#endif
};

// Class used for Blueprint nodes blocking on Bank Load
class FWaitEndBankAction : public FAkPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink = 0;
	FWeakObjectPtr CallbackTarget;
	FThreadSafeBool ActionDone;

	FWaitEndBankAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, ActionDone(false)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		Response.FinishAndTriggerIf(ActionDone, ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Waiting for AkBank to finish loading or unloading.");
	}
#endif
};

class FSetCurrentAudioCultureAction : public FAkPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink = 0;
	FWeakObjectPtr CallbackTarget;
	FThreadSafeBool ActionDone;

	FSetCurrentAudioCultureAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, ActionDone(false)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		Response.FinishAndTriggerIf(ActionDone, ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Waiting for SetCurrentAudioCultureAsync to finish.");
	}
#endif
};

/*=============================================================================
End - Ak Callback Blueprint classes and structures.
=============================================================================*/

/*=============================================================================

Begin - AkExternalSources enums and structures. Known limitations:
	- It is not possible to set external sources from memory using Blueprint
	- It is not possible to stream external sources from disk

=============================================================================*/

UENUM(BlueprintType)
enum class AkCodecId : uint8
{	
	///< None: required default.
	None = 0,

	///< PCM encoding
	PCM = AKCODECID_PCM,

	///< ADPCM encoding
	ADPCM = AKCODECID_ADPCM,
	
	///< XMA encoding
	XMA = AKCODECID_XMA,

	///< Vorbis encoding
	Vorbis = AKCODECID_VORBIS,

	///< AAC encoding (only available on Apple devices) -- see AkAACFactory.h
	AAC = AKCODECID_AAC,

	///< ATRAC-9 encoding
	ATRAC9 = AKCODECID_ATRAC9,
	
	///< OpusNX encoding
	OpusNX = AKCODECID_OPUSNX,

	///< Opus encoding
	AkOpus = AKCODECID_AKOPUS,

	///< WEM Opus encoding
	AkOpusWEM = AKCODECID_AKOPUS_WEM
};

USTRUCT(BlueprintType)
struct FAkExternalSourceInfo
{
	GENERATED_BODY()

	/// Name of the source given in the project. (The Cookie ID)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkExternalSourceInfo")
	FString ExternalSrcName;
	
	/// Codec ID for the file. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkExternalSourceInfo")
	AkCodecId CodecID;
	
	/// File path for the source. (Relative to ExternalSources folder in your sound bank folder)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkExternalSourceInfo")
	FString FileName;

	/// Hard link to the media asset to use, it can be either streamed or not using IsStreamed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkExternalSourceInfo")
	class UAkExternalMediaAsset* ExternalSourceAsset;

	/// Is the ExternalSourceAsset streamed or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audiokinetic|AkExternalSourceInfo")
	bool IsStreamed = true;
};

struct FAkSDKExternalSourceArray :  public TSharedFromThis<FAkSDKExternalSourceArray, ESPMode::ThreadSafe>
{
	FAkSDKExternalSourceArray() {}
	FAkSDKExternalSourceArray(const TArray<FAkExternalSourceInfo>& BlueprintArray);
	~FAkSDKExternalSourceArray();

	TArray<AkExternalSourceInfo> ExternalSourceArray;
};

class UAkAudioEvent;
class FWaitEndOfEventAsyncAction : public FWaitEndOfEventAction
{
public:
	int32* PlayingID = nullptr;
	TFuture<AkPlayingID> FuturePlayingID;
	TArray<FAkExternalSourceInfo> ExternalSources;
	UAkAudioEvent* AkEvent = nullptr;
	bool bStopWhenAttachedToDestroyed = true;

	FWaitEndOfEventAsyncAction(const FLatentActionInfo& LatentInfo, int32* PlayingID)
		: FWaitEndOfEventAction(LatentInfo)
		, PlayingID(PlayingID)
	{
	}

	FWaitEndOfEventAsyncAction(const FLatentActionInfo& LatentInfo, int32* PlayingID, const TArray<FAkExternalSourceInfo>& ExtSrc, UAkAudioEvent* Event, bool StopWhenAttachedToDestroyed)
		: FWaitEndOfEventAction(LatentInfo)
		, PlayingID(PlayingID)
		, ExternalSources(ExtSrc)
		, AkEvent(Event)
		, bStopWhenAttachedToDestroyed(StopWhenAttachedToDestroyed)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Waiting for async posted AkEvent to end.");
	}
#endif
};



/*=============================================================================
End - AkExternalSources enums and structures.
=============================================================================*/

struct AkDeviceAndWorld
{
	class FAkAudioDevice* AkAudioDevice = nullptr;
	class UWorld* CurrentWorld = nullptr;
	AkDeviceAndWorld(AActor* in_pActor);


	AkDeviceAndWorld(const UObject* in_pWorldContextObject);

	bool IsValid() const;
};
