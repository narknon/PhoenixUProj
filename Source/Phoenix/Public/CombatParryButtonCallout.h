#pragma once
#include "CoreMinimal.h"
#include "ECombatParryType.h"
#include "PhoenixUserWidget.h"
#include "CombatParryButtonCallout.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCombatParryButtonCallout : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECombatParryType CombatParryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInPerfectTimingWindow;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpectedLifetime;
    
public:
    UCombatParryButtonCallout();
    UFUNCTION(BlueprintCallable)
    void SetPerfectTimingState(const bool bPerfectTiming);
    
    UFUNCTION(BlueprintCallable)
    void SetParryType(const ECombatParryType ParryType);
    
    UFUNCTION(BlueprintCallable)
    void SetExpectedLifetime(float LifeTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputDeviceChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintSetPerfectTimingState(const bool bPerfectTiming);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintSetParryType(const ECombatParryType ParryType);
    
};

