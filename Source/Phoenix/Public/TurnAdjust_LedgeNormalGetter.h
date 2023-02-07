#pragma once
#include "CoreMinimal.h"
#include "TurnAdjust_TargetDirectionGetter.h"
#include "TurnAdjust_LedgeNormalGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnAdjust_LedgeNormalGetter : public UTurnAdjust_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnAdjust_LedgeNormalGetter();
};

