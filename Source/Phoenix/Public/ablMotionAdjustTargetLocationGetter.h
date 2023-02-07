#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ablMotionAdjustTargetLocationGetter.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class UablMotionAdjustTargetLocationGetter : public UObject {
    GENERATED_BODY()
public:
    UablMotionAdjustTargetLocationGetter();
};

