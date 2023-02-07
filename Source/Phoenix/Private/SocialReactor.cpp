#include "SocialReactor.h"

class AActor;
class APawn;
class UAblAbilityContext;
class UObject;
class USocialReactor;

bool USocialReactor::ValidateInteractionType(FName InTargetName, AActor* InTargetActor, TEnumAsByte<SocialInteractionTypeIDs> InInteractionType) {
    return false;
}

void USocialReactor::ToggleAmbientChatterTopic(AmbientChatterTopicIDs InTopic, bool bInTurnOn) {
}

void USocialReactor::StartSettingMissionGossipCalloutsMuted(bool InMuted, EStandardManagedPriority InPriority, UObject* InCaller) {
}

void USocialReactor::StartEmoAbility(APawn* InActorPawn) {
}

void USocialReactor::SetEmotionalState(FName InActorName, TEnumAsByte<SocialSemanticIDs> InSocialEmotion, int32 InMagnitude) {
}

void USocialReactor::ReportSocialAction(SocialActionTypes inActionID, const FString& inActionData, const FString& inLocationName, const FString& InTargetName) {
}

void USocialReactor::PerformNewDay() {
}

void USocialReactor::PerformEndOfDayCleanup() {
}

void USocialReactor::OnSaveGameLoaded() {
}

void USocialReactor::OnAbilityStart(int32 ChannelIndex, UAblAbilityContext* AbilityContext) {
}

bool USocialReactor::MissionGossipCalloutsMuted() {
    return false;
}

bool USocialReactor::HasIdentity(const FName& InTargetName, TEnumAsByte<SocialSemanticIDs> Identity) {
    return false;
}

USocialReactor* USocialReactor::GetTheSocialReactor() {
    return NULL;
}

TArray<FName> USocialReactor::GetIdentityNames(const FName& InTargetName) {
    return TArray<FName>();
}

TArray<FName> USocialReactor::GetIdentityList() const {
    return TArray<FName>();
}

void USocialReactor::GetConversationOptions(FName InTargetName, AActor* InTargetActor, TArray<FSocialConversationData>& outConversationOptions) {
}

void USocialReactor::FinishSettingMissionGossipCalloutsMuted(EStandardManagedPriority InPriority, UObject* InCaller) {
}

void USocialReactor::EndDialogInteraction(FName InTargetName) {
}

void USocialReactor::BeginDialogInteraction(FName InTargetName) {
}

bool USocialReactor::AllowConversation(const FString& InTargetName, const FString& inMyName) {
    return false;
}

bool USocialReactor::AddNewIdentity(const FName& InCharacterName, const FName& InIdentityName) {
    return false;
}

USocialReactor::USocialReactor() {
}

