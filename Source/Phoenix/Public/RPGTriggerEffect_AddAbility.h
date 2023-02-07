#pragma once
#include "CoreMinimal.h"
#include "ETimedAbilityUnit.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_AddAbility.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_AddAbility : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<URPGAbilityBase> RPGAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETimedAbilityUnit> DurationUnit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseIngameSimulationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetOnDayEnd;
    
public:
    URPGTriggerEffect_AddAbility();
};

