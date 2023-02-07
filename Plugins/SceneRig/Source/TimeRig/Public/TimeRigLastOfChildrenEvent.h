#pragma once
#include "CoreMinimal.h"
#include "TimeRigEvent.h"
#include "TimeRigLastOfChildrenEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UTimeRigLastOfChildrenEvent : public UTimeRigEvent {
    GENERATED_BODY()
public:
    UTimeRigLastOfChildrenEvent();
};

