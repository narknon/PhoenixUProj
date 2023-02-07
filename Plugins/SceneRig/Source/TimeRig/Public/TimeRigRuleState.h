#pragma once
#include "CoreMinimal.h"
#include "TimeRigIntervalState.h"
#include "TimeRigParentElement.h"
#include "TimeRigRuleState.generated.h"

class UTimeRig;
class UTimeRigInstanceContext;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigRuleState : public UTimeRigIntervalState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig* GeneratedTimeRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRigInstanceContext* InstanceContext;
    
    UTimeRigRuleState();
    
    // Fix for true pure virtual functions not being implemented
};

