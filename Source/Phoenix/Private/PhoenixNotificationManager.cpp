#include "PhoenixNotificationManager.h"

class UObject;

void UPhoenixNotificationManager::QueueNotification(UObject* Owner, ENotificationCategory Category, const FString& CallbackName, int32 Priority) {
}

void UPhoenixNotificationManager::PauseNotifications(bool ShouldPause, const UObject* Provider, FName ProviderName) {
}

void UPhoenixNotificationManager::PauseNotificationCategory(bool ShouldPause, ENotificationCategory Category, const UObject* Provider, FName ProviderName) {
}

void UPhoenixNotificationManager::NotificationComplete(ENotificationCategory Category) {
}

bool UPhoenixNotificationManager::IsNotificationPending(ENotificationCategory Category) {
    return false;
}

bool UPhoenixNotificationManager::IsNotificationActive(ENotificationCategory Category) {
    return false;
}

int32 UPhoenixNotificationManager::GetConcurrentNotifications(ENotificationCategory Category) {
    return 0;
}

TArray<ENotificationCategory> UPhoenixNotificationManager::GetBlockingCategories(ENotificationCategory Category) {
    return TArray<ENotificationCategory>();
}

void UPhoenixNotificationManager::ClearPendingNotificationsInCategory(ENotificationCategory Category) {
}

void UPhoenixNotificationManager::ClearActiveNotificationsInCategory(ENotificationCategory Category) {
}

UPhoenixNotificationManager::UPhoenixNotificationManager() {
}

