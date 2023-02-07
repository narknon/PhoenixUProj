#pragma once
#include "CoreMinimal.h"
#include "TimeRigIntervalState.h"
#include "TimeRigParentElement.h"
#include "TimeRigState.generated.h"

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigState : public UTimeRigIntervalState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UTimeRigState();
    
    // Fix for true pure virtual functions not being implemented
};

