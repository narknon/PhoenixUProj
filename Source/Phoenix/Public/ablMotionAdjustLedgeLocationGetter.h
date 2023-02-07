#pragma once
#include "CoreMinimal.h"
#include "ablMotionAdjustTargetLocationGetter.h"
#include "ablMotionAdjustLedgeLocationGetter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablMotionAdjustLedgeLocationGetter : public UablMotionAdjustTargetLocationGetter {
    GENERATED_BODY()
public:
    UablMotionAdjustLedgeLocationGetter();
};

