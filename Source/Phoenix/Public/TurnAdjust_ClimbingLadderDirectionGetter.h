#pragma once
#include "CoreMinimal.h"
#include "TurnAdjust_TargetDirectionGetter.h"
#include "TurnAdjust_ClimbingLadderDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnAdjust_ClimbingLadderDirectionGetter : public UTurnAdjust_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnAdjust_ClimbingLadderDirectionGetter();
};

