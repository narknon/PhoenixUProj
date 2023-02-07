#include "AnalyticsManager.h"

class AActor;
class UAnalyticsManager;

void UAnalyticsManager::SetUsingFloo(const bool UsingFloo) {
}

void UAnalyticsManager::SetSaveSlot(const int32 SaveSlot) {
}

void UAnalyticsManager::SetNaturalPlaythrough(const bool bNatural) {
}

void UAnalyticsManager::OnSaveGameLoaded() {
}

void UAnalyticsManager::HeartbeatUpdateMountState(const FString& MountType) {
}

void UAnalyticsManager::HandleSphinxPuzzle(const FString& Name, const FString& Type, const EInteractiveState InteractiveState) {
}

void UAnalyticsManager::HandleSpellFunnel(const bool Conjuration, const int32 StepNumber, const FString& FunnelAction, const FString& Selection, const FString& Transformation, const FString& Color, const FString& SelectionID) {
}

void UAnalyticsManager::HandleResourceFlow(const FString& Resource, const float ChangeAmount, const float FinalAmount, const FString& Source, const FString& SourceDetail, const FString& ResourceFlowID, const FString& ResourceCategory) {
}

void UAnalyticsManager::HandlePuzzle(const FString& PuzzleName, const bool Start, const FString& PuzzleType) {
}

void UAnalyticsManager::HandlePlayerAvatarUpdate(const FString& PresetType, const FString& PresetValue) {
}

void UAnalyticsManager::HandleOptionSet(const FString& OptionName, const FString& OptionType, const FString& StringValue, const bool BoolValue, const float FloatValue) {
}

void UAnalyticsManager::HandleNPCAction(const FString& NPCID, const FString& Action, const FString& ActionDetail, const FString& ConversationID, const FString& DialogueText, const int32 ChoiceNum, const int32 NumChoices) {
}

void UAnalyticsManager::HandleMenuItemSelect(const FName menuItemName, const FString& selectAction) {
}

void UAnalyticsManager::HandleMenuAction(const FString& MenuName, const FString& Action, const FString& Selection, const FString& SelectionDetail, const bool LockedToPage) {
}

void UAnalyticsManager::HandleInteraction(const AActor* Target) {
}

void UAnalyticsManager::HandleFirstTimeLaunch() {
}

void UAnalyticsManager::HandleConversationChoice(const FString& DialogueID, const int32 ChoiceNum, const int32 NumChoices) {
}

FString UAnalyticsManager::GetCharacterID() {
    return TEXT("");
}

UAnalyticsManager* UAnalyticsManager::Get() {
    return NULL;
}

void UAnalyticsManager::AnalyticsEventAction(const FString& ActionName, const FString& SubactionName, const bool ActionResult, const FString& ResultExplained, const FString& ActionDetail) {
}

UAnalyticsManager::UAnalyticsManager() {
}

