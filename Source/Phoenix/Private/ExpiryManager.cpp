#include "ExpiryManager.h"

class UExpiryManager;

bool UExpiryManager::RefreshExpiry(const FString& UniqueId, int64 ExpireTime, EExpiryTypes ExpiryType) {
    return false;
}

void UExpiryManager::OnSaveGameLoaded() {
}

void UExpiryManager::OnGameToBeSaved() {
}

bool UExpiryManager::HasExpiry(const FString& UniqueId, EExpiryTypes ExpiryType) {
    return false;
}

int64 UExpiryManager::GetExpiry(const FString& UniqueId, EExpiryTypes ExpiryType) {
    return 0;
}

UExpiryManager* UExpiryManager::Get() {
    return NULL;
}

bool UExpiryManager::ClearExpiry(const FString& UniqueId, EExpiryTypes ExpiryType) {
    return false;
}

bool UExpiryManager::AddExpiry(const FString& UniqueId, int64 ExpireTime, EExpiryTypes ExpiryType) {
    return false;
}

UExpiryManager::UExpiryManager() {
}

