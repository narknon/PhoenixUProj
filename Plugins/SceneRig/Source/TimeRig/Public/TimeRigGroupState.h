#pragma once
#include "CoreMinimal.h"
#include "TimeRigIntervalState.h"
#include "TimeRigParentElement.h"
#include "TimeRigGroupState.generated.h"

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigGroupState : public UTimeRigIntervalState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UTimeRigGroupState();
    
    // Fix for true pure virtual functions not being implemented
};

