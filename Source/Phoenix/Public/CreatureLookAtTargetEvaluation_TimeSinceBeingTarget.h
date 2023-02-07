#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Float.h"
#include "CreatureLookAtTargetEvaluation_TimeSinceBeingTarget.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_TimeSinceBeingTarget : public UCreatureLookAtTargetEvaluation_Float {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_TimeSinceBeingTarget();
};

