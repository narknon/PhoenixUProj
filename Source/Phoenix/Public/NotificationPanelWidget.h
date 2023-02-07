#pragma once
#include "CoreMinimal.h"
#include "ChallengeNotificationData.h"
#include "CollectionNotificationData.h"
#include "HUDElementGroup.h"
#include "PickupNotificationData.h"
#include "NotificationPanelWidget.generated.h"

class UObject;
class UPooledVerticalBox;

UCLASS(Blueprintable, EditInlineNew)
class UNotificationPanelWidget : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPooledVerticalBox* NotificationsBox;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsActiveChallengeUpdateIncrementable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsActiveMoneyNotificationIncrementable;
    
public:
    UNotificationPanelWidget();
    UFUNCTION(BlueprintCallable)
    void RequestCollectionObtainedNotification(FCollectionNotificationData NewItem);
    
    UFUNCTION(BlueprintCallable)
    void RequestCollectionKnownNotification(FCollectionNotificationData NewItem);
    
    UFUNCTION(BlueprintCallable)
    void RequestChallengeUpdatedNotification(FChallengeNotificationData NewItem);
    
    UFUNCTION(BlueprintCallable)
    void RequestChallengeCompleteNotification(FChallengeNotificationData NewItem);
    
    UFUNCTION(BlueprintCallable)
    void OnNotificationAborted(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void OnDisplayPickupNotification(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void OnDisplayMoneyNotification(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void OnDisplayCollectionObtainedNotification(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void OnDisplayCollectionKnownNotification(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void OnDisplayChallengeUpdatedNotification(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void OnDisplayChallengeCompleteNotification(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void ItemCollected(FPickupNotificationData NewItem);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void IncrementCurrentMoneyNotification(int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void IncrementCurrentChallengeUpdate(FChallengeNotificationData ItemData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddPickupNotification(FPickupNotificationData ItemData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddMoneyNotification(FPickupNotificationData ItemData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddCollectionObtainedNotification(FCollectionNotificationData ItemData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddCollectionKnownNotification(FCollectionNotificationData ItemData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddChallengeUpdatedNotification(FChallengeNotificationData ItemData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddChallengeCompleteNotification(FChallengeNotificationData ItemData);
    
};

