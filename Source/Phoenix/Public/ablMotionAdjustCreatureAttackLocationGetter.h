#pragma once
#include "CoreMinimal.h"
#include "ablMotionAdjustTargetLocationGetter.h"
#include "ablMotionAdjustCreatureAttackLocationGetter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablMotionAdjustCreatureAttackLocationGetter : public UablMotionAdjustTargetLocationGetter {
    GENERATED_BODY()
public:
    UablMotionAdjustCreatureAttackLocationGetter();
};

