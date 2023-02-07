#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TurnAdjust_TargetDirectionGetter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class UTurnAdjust_TargetDirectionGetter : public UObject {
    GENERATED_BODY()
public:
    UTurnAdjust_TargetDirectionGetter();
};

