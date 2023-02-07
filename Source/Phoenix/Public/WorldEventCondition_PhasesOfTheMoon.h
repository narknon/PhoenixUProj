#pragma once
#include "CoreMinimal.h"
#include "ESchedulerMoonPhase.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_PhasesOfTheMoon.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_PhasesOfTheMoon : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<ESchedulerMoonPhase>> MoonPhasesToCheck;
    
    UWorldEventCondition_PhasesOfTheMoon();
};

