#include "WorldEventManager.h"

class ALevelScriptActor;
class AWorldEventLocationActor;
class UObject;
class UWorldEventManager;

void UWorldEventManager::StartSettingEventStreamingPausedValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator) {
}

void UWorldEventManager::OnWorldEventLoaded(AWorldEventLocationActor* locationActor, const FWorldEventDataRow& dataRow) {
}

void UWorldEventManager::OnSaveGameLoaded() {
}

void UWorldEventManager::OnNewGame() {
}

void UWorldEventManager::OnGameToBeSaved() {
}

FGameplayTagContainer UWorldEventManager::GetWorldEventLocationTags(ALevelScriptActor* LevelScript) {
    return FGameplayTagContainer{};
}

UWorldEventManager* UWorldEventManager::Get() {
    return NULL;
}

void UWorldEventManager::FinishSettingEventStreamingPausedValue(EStandardManagedPriority Priority, UObject* InInstigator) {
}

UWorldEventManager::UWorldEventManager() {
    this->WorldEventsDataTable = NULL;
}

