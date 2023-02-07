#pragma once
#include "CoreMinimal.h"
#include "TimeRigElementState.h"
#include "TimeRigParentElement.h"
#include "TimeRigPlaceholderState.generated.h"

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigPlaceholderState : public UTimeRigElementState, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UTimeRigPlaceholderState();
    
    // Fix for true pure virtual functions not being implemented
};

