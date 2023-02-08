#pragma once
#include "CoreMinimal.h"
#include "AvaAudioDialogueMetaData.h"
#include "AvaAudioPrepareDialogueSequenceResult.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HermesBPDelegateHandle.h"
#include "AudioDialogueLineData.h"
#include "AvaAudioDialogueFlags.h"
#include "DialogueConversationReference.h"
#include "DialogueEventCompleteDelegateDelegate.h"
#include "DialogueSequenceReference.h"
#include "EGenderVoice.h"
#include "MultiFX2_Dialogue.h"
#include "AvaAudioGameplayStatics.generated.h"

class AActor;

class UObject;

UCLASS(Blueprintable)
class PHOENIX_API UAvaAudioGameplayStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesAudioDialogueLineStartedDataDelegate, const UObject*, Caller, const FAudioDialogueLineData&, AudioDialogueLineData);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesAudioDialogueLineEndedDataDelegate, const UObject*, Caller, const FAudioDialogueLineData&, AudioDialogueLineData);
    
    UAvaAudioGameplayStatics();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void WriteStringToSpeechLog(const FString& LogString);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void StopPlayingID(int32& PlayingID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void StopDialogue(int32 DialogueHandle);
    
    UFUNCTION(BlueprintCallable)
    static bool SetPlayerGenderVoice(EGenderVoice NewGenderVoice);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void ResumeDialogueStartedPaused(int32 DialogueHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void RequestDialogueCompleteNotification(int32 DialogueHandle, const FDialogueEventCompleteDelegate& Delegate_DialogueEventComplete);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void RemoveStateFromStackByName(FName stateGroup, FName State, int32 Priority);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void RemoveStateFromStack(int32 StackHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 QueueDialogueEventWithParametersByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 QueueDialogueEventWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 QueueDialogueEventByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 QueueDialogueEventAtLocationWithParametersByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 QueueDialogueEventAtLocationWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 QueueDialogueEventAtLocationByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 QueueDialogueEventAtLocation(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 QueueDialogueEvent(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool QueryDialogueEventPotentialCast(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, TArray<FName>& Out_CharacterIDCast);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool PrepareDialogueSequenceByReference_BP(FDialogueConversationReference DialogueEventName, const TArray<AActor*>& Actors, const TArray<FString>& In_AdditionalCharacterIDs, TArray<FAvaAudioPrepareDialogueSequenceResult>& Out_Results, AvaAudioDialogueFlags flags, bool bStartBuffering);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool PrepareDialogueSequence_BP(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, const TArray<AActor*>& Actors, const TArray<FString>& In_AdditionalCharacterIDs, TArray<FAvaAudioPrepareDialogueSequenceResult>& Out_Results, AvaAudioDialogueFlags flags, bool bStartBuffering);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool PrepareDialogueEventWithParametersByReference_BP(FDialogueConversationReference DialogueEventName, AActor* Actor, const TMap<FString, FString>& In_Parameters, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool PrepareDialogueEventWithParameters_BP(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, const TMap<FString, FString>& In_Parameters, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool PrepareDialogueEventByReference_BP(FDialogueConversationReference DialogueEventName, AActor* Actor, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool PrepareDialogueEvent_BP(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering);
    
    UFUNCTION(BlueprintCallable)
    static void PostEventPlayerVoice();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostDialogueEventWithParametersByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostDialogueEventWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostDialogueEventByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 PostDialogueEventAtLocationWithParametersByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 PostDialogueEventAtLocationWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 PostDialogueEventAtLocationByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static int32 PostDialogueEventAtLocation(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PostDialogueEvent(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PlayDialogueSequenceWithCharacterIDsByReference(FDialogueConversationReference DialogueEventName, TArray<AActor*> Actors, TArray<FString> In_AdditionalCharacterIDs, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PlayDialogueSequenceWithCharacterIDs(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, TArray<AActor*> Actors, TArray<FString> In_AdditionalCharacterIDs, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PlayDialogueSequenceByReference(FDialogueConversationReference DialogueEventName, TArray<AActor*> Actors, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 PlayDialogueSequence(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, TArray<AActor*> Actors, AvaAudioDialogueFlags flags);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void MusicStackRemoveEventByName(const FString& EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
    static void MusicStackAddEventAtLocationByName(const FString& EventName, int32 Priority, FVector Location, FRotator Orientation, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void LatchSpell(FName AudioSpellName, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool IsStateOnTopOfStack(FName stateGroup, FName State);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool IsDialogueEventActive(int32 DialogueHandle);
    
    UFUNCTION(BlueprintCallable)
    static void InitActorAudio(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindAudioDialogueLineStartedData(UAvaAudioGameplayStatics::FHermesAudioDialogueLineStartedDataDelegate Delegate_AudioDialogueLineStartedData, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindAudioDialogueLineEndedData(UAvaAudioGameplayStatics::FHermesAudioDialogueLineEndedDataDelegate Delegate_AudioDialogueLineEndedData, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static bool GetSourcePlayPosition(int32 DialogueHandle, float& Out_AudioSeconds, float& Out_LipsyncPrerollAdjustedSeconds);
    
    UFUNCTION(BlueprintCallable)
    static EGenderVoice GetPlayerGenderVoice();
    
    UFUNCTION(BlueprintCallable)
    static bool DialogueSequenceReferenceIsValid(const FDialogueSequenceReference& Reference);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool DialogueReferenceIsValid(FDialogueConversationReference DialogueReference);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void DebugDialogueUnload();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 DebugDialoguePlay(AActor* Actor, FName lineID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void DebugDialogueLoad();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void DebugDialogueChangeLanguage(const FString& Language);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static void ClearDialogueCompleteNotification(int32 DialogueHandle);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static int32 AddStateToStack(FName stateGroup, FName State, int32 Priority);
    
};

