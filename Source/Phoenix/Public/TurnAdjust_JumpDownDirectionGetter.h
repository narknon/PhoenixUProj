#pragma once
#include "CoreMinimal.h"
#include "TurnAdjust_TargetDirectionGetter.h"
#include "TurnAdjust_JumpDownDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnAdjust_JumpDownDirectionGetter : public UTurnAdjust_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnAdjust_JumpDownDirectionGetter();
};

