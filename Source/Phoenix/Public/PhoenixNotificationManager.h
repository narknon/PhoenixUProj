#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ENotificationCategory.h"
#include "PhoenixNotificationManager.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UPhoenixNotificationManager : public UObject {
    GENERATED_BODY()
public:
    UPhoenixNotificationManager();
    UFUNCTION(BlueprintCallable)
    void QueueNotification(UObject* Owner, ENotificationCategory Category, const FString& CallbackName, int32 Priority);
    
    UFUNCTION(BlueprintCallable)
    void PauseNotifications(bool ShouldPause, const UObject* Provider, FName ProviderName);
    
    UFUNCTION(BlueprintCallable)
    void PauseNotificationCategory(bool ShouldPause, ENotificationCategory Category, const UObject* Provider, FName ProviderName);
    
    UFUNCTION(BlueprintCallable)
    void NotificationComplete(ENotificationCategory Category);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNotificationPending(ENotificationCategory Category);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNotificationActive(ENotificationCategory Category);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetConcurrentNotifications(ENotificationCategory Category);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ENotificationCategory> GetBlockingCategories(ENotificationCategory Category);
    
    UFUNCTION(BlueprintCallable)
    void ClearPendingNotificationsInCategory(ENotificationCategory Category);
    
    UFUNCTION(BlueprintCallable)
    void ClearActiveNotificationsInCategory(ENotificationCategory Category);
    
};

