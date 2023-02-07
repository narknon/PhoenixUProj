#include "AcknowledgementManager.h"

class AActor;
class UAcknowledgementManager;

void UAcknowledgementManager::UpdateMiscStatStatic(const FName Key, const FString& Value) {
}

void UAcknowledgementManager::UpdateMiscIntStatStatic(const FName Key, const int32 Value) {
}

void UAcknowledgementManager::UpdateMiscBoolStatStatic(const FName Key, const bool bValue) {
}

void UAcknowledgementManager::SetSpecialSpeakerForAcknowledgement(AActor* InSpecialSpeaker) {
}

void UAcknowledgementManager::SetSpecialSpeakerByDBIDForAcknowledgement(const FName& InSpecialSpeakerName) {
}

void UAcknowledgementManager::OnSaveGameLoaded() {
}

void UAcknowledgementManager::OnPreLoadGame() {
}

void UAcknowledgementManager::OnNewGame() {
}

void UAcknowledgementManager::HandleStatChanged(const FName StatID, const int32 Value, const int32 Delta) {
}

void UAcknowledgementManager::HandleHouseChestAcknowledgement() {
}

void UAcknowledgementManager::HandleFleshLoaded(AActor* InFleshActor) {
}

UAcknowledgementManager* UAcknowledgementManager::GetAcknowledgementManager() {
    return NULL;
}

UAcknowledgementManager* UAcknowledgementManager::Get() {
    return NULL;
}

UAcknowledgementManager::UAcknowledgementManager() {
    this->AcknowledgementLogicContainer = NULL;
}

