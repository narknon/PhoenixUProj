#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigMatchParentEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigMatchParentEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UTimeRigMatchParentEvent();
};

