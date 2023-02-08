#include "AvaAudioGameplayStatics.h"



void UAvaAudioGameplayStatics::WriteStringToSpeechLog(const FString& LogString) {
}

void UAvaAudioGameplayStatics::StopPlayingID(int32& PlayingID) {
}

void UAvaAudioGameplayStatics::StopDialogue(int32 DialogueHandle) {
}

bool UAvaAudioGameplayStatics::SetPlayerGenderVoice(EGenderVoice NewGenderVoice) {
    return false;
}

void UAvaAudioGameplayStatics::ResumeDialogueStartedPaused(int32 DialogueHandle) {
}

void UAvaAudioGameplayStatics::RequestDialogueCompleteNotification(int32 DialogueHandle, const FDialogueEventCompleteDelegate& Delegate_DialogueEventComplete) {
}

void UAvaAudioGameplayStatics::RemoveStateFromStackByName(FName stateGroup, FName State, int32 Priority) {
}

void UAvaAudioGameplayStatics::RemoveStateFromStack(int32 StackHandle) {
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventWithParametersByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventAtLocationWithParametersByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventAtLocationWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventAtLocationByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEventAtLocation(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, int32 QueueToHandle, float QueueWithDelaySeconds, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::QueueDialogueEvent(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, int32 QueueToHandle, float QueueWithDelaySeconds, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

bool UAvaAudioGameplayStatics::QueryDialogueEventPotentialCast(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, TArray<FName>& Out_CharacterIDCast) {
    return false;
}

bool UAvaAudioGameplayStatics::PrepareDialogueSequenceByReference_BP(FDialogueConversationReference DialogueEventName, const TArray<AActor*>& Actors, const TArray<FString>& In_AdditionalCharacterIDs, TArray<FAvaAudioPrepareDialogueSequenceResult>& Out_Results, AvaAudioDialogueFlags flags, bool bStartBuffering) {
    return false;
}

bool UAvaAudioGameplayStatics::PrepareDialogueSequence_BP(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, const TArray<AActor*>& Actors, const TArray<FString>& In_AdditionalCharacterIDs, TArray<FAvaAudioPrepareDialogueSequenceResult>& Out_Results, AvaAudioDialogueFlags flags, bool bStartBuffering) {
    return false;
}

bool UAvaAudioGameplayStatics::PrepareDialogueEventWithParametersByReference_BP(FDialogueConversationReference DialogueEventName, AActor* Actor, const TMap<FString, FString>& In_Parameters, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering) {
    return false;
}

bool UAvaAudioGameplayStatics::PrepareDialogueEventWithParameters_BP(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, const TMap<FString, FString>& In_Parameters, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering) {
    return false;
}

bool UAvaAudioGameplayStatics::PrepareDialogueEventByReference_BP(FDialogueConversationReference DialogueEventName, AActor* Actor, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering) {
    return false;
}

bool UAvaAudioGameplayStatics::PrepareDialogueEvent_BP(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, TMap<FString, FString>& Out_Parameters, FAvaAudioDialogueMetaData& Out_MetaData, bool bStartBuffering) {
    return false;
}

void UAvaAudioGameplayStatics::PostEventPlayerVoice() {
}

int32 UAvaAudioGameplayStatics::PostDialogueEventWithParametersByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEventWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, const TMap<FString, FString>& Parameters, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEventByReference(FDialogueConversationReference DialogueEventName, AActor* Actor, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEventAtLocationWithParametersByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEventAtLocationWithParameters(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, const TMap<FString, FString>& Parameters, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEventAtLocationByReference(FDialogueConversationReference DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEventAtLocation(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, FVector Location, FRotator Orientation, UObject* WorldContextObject, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PostDialogueEvent(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, AActor* Actor, bool bStopWhenAttachedToDestroyed, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PlayDialogueSequenceWithCharacterIDsByReference(FDialogueConversationReference DialogueEventName, TArray<AActor*> Actors, TArray<FString> In_AdditionalCharacterIDs, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PlayDialogueSequenceWithCharacterIDs(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, TArray<AActor*> Actors, TArray<FString> In_AdditionalCharacterIDs, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PlayDialogueSequenceByReference(FDialogueConversationReference DialogueEventName, TArray<AActor*> Actors, AvaAudioDialogueFlags flags) {
    return 0;
}

int32 UAvaAudioGameplayStatics::PlayDialogueSequence(UAvaAudioDialogueEvent* DialogueEvent, const FString& DialogueEventName, TArray<AActor*> Actors, AvaAudioDialogueFlags flags) {
    return 0;
}

void UAvaAudioGameplayStatics::MusicStackRemoveEventByName(const FString& EventName) {
}

void UAvaAudioGameplayStatics::MusicStackAddEventAtLocationByName(const FString& EventName, int32 Priority, FVector Location, FRotator Orientation, UObject* WorldContextObject) {
}

void UAvaAudioGameplayStatics::LatchSpell(FName AudioSpellName, AActor* Actor) {
}

bool UAvaAudioGameplayStatics::IsStateOnTopOfStack(FName stateGroup, FName State) {
    return false;
}

bool UAvaAudioGameplayStatics::IsDialogueEventActive(int32 DialogueHandle) {
    return false;
}

void UAvaAudioGameplayStatics::InitActorAudio(AActor* Actor) {
}

void UAvaAudioGameplayStatics::HermesBindAudioDialogueLineStartedData(UAvaAudioGameplayStatics::FHermesAudioDialogueLineStartedDataDelegate Delegate_AudioDialogueLineStartedData, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

void UAvaAudioGameplayStatics::HermesBindAudioDialogueLineEndedData(UAvaAudioGameplayStatics::FHermesAudioDialogueLineEndedDataDelegate Delegate_AudioDialogueLineEndedData, const UObject* Owner, FHermesBPDelegateHandle& Handle) {
}

bool UAvaAudioGameplayStatics::GetSourcePlayPosition(int32 DialogueHandle, float& Out_AudioSeconds, float& Out_LipsyncPrerollAdjustedSeconds) {
    return false;
}

EGenderVoice UAvaAudioGameplayStatics::GetPlayerGenderVoice() {
    return EGenderVoice::VOICE_MALE;
}

bool UAvaAudioGameplayStatics::DialogueSequenceReferenceIsValid(const FDialogueSequenceReference& Reference) {
    return false;
}

bool UAvaAudioGameplayStatics::DialogueReferenceIsValid(FDialogueConversationReference DialogueReference) {
    return false;
}

void UAvaAudioGameplayStatics::DebugDialogueUnload() {
}

int32 UAvaAudioGameplayStatics::DebugDialoguePlay(AActor* Actor, FName lineID) {
    return 0;
}

void UAvaAudioGameplayStatics::DebugDialogueLoad() {
}

void UAvaAudioGameplayStatics::DebugDialogueChangeLanguage(const FString& Language) {
}

void UAvaAudioGameplayStatics::ClearDialogueCompleteNotification(int32 DialogueHandle) {
}

int32 UAvaAudioGameplayStatics::AddStateToStack(FName stateGroup, FName State, int32 Priority) {
    return 0;
}

UAvaAudioGameplayStatics::UAvaAudioGameplayStatics() {
}

