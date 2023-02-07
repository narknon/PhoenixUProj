#pragma once
#include "CoreMinimal.h"
#include "ExperienceChange.h"
#include "HUDElementGroup.h"
#include "XPMeterBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UXPMeterBase : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ActiveNotificationStackable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExperienceChange> NotificationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFillTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentFillTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFilling;
    
    UXPMeterBase();
    UFUNCTION(BlueprintCallable)
    bool TryStackNotification(FExperienceChange XPChangeData);
    
    UFUNCTION(BlueprintCallable)
    void StartAddingXP(float FillDuration, float StartTime);
    
    UFUNCTION(BlueprintCallable)
    void RemoveFromNotificationQueue();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnXPFillWrap();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnXPAdded(float FillPct);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartAddingXP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishAddingXP();
    
private:
    UFUNCTION(BlueprintCallable)
    void AddXP();
    
};

