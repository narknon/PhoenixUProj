#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblTaskConditionAnimNotifyScratchpad.generated.h"

class UAblAbilityContext;
class UAnimationAsset;

UCLASS(Blueprintable, NonTransient)
class UAblTaskConditionAnimNotifyScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<FName> EventNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEventReceived;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEventExists;
    
    UAblTaskConditionAnimNotifyScratchpad();
    UFUNCTION(BlueprintCallable)
    void OnAnimationPlayed(float InCurrentTime, const UAnimationAsset* InAnimationAsset, const UAblAbilityContext* Context);
    
};

