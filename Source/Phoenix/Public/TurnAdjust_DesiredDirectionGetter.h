#pragma once
#include "CoreMinimal.h"
#include "TurnAdjust_TargetDirectionGetter.h"
#include "TurnAdjust_DesiredDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnAdjust_DesiredDirectionGetter : public UTurnAdjust_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnAdjust_DesiredDirectionGetter();
};

