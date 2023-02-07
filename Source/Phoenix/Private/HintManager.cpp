#include "HintManager.h"

class UGameLogicObject;
class UHint;

void UHintManager::OnSaveGameLoaded() {
}

void UHintManager::OnGameToBeSaved() {
}

UGameLogicObject* UHintManager::GetHintManagerGameLogicObject() {
    return NULL;
}

UHint* UHintManager::GetHint(const FString& HintKey) {
    return NULL;
}

void UHintManager::DestroyHint(UHint* Hint) {
}

UHint* UHintManager::CreateHint(const FString& Name) {
    return NULL;
}

UHintManager::UHintManager() {
    this->GameLogicObject = NULL;
}

