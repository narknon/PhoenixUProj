#pragma once
#include "CoreMinimal.h"
#include "TimeRigIntervalState.h"
#include "TimeRigParentElement.h"
#include "TimeRigChainState.generated.h"

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigChainState : public UTimeRigIntervalState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UTimeRigChainState();
    
    // Fix for true pure virtual functions not being implemented
};

