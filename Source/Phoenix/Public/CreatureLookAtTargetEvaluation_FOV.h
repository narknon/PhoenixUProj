#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Float.h"
#include "CreatureLookAtTargetEvaluation_FOV.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_FOV : public UCreatureLookAtTargetEvaluation_Float {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_FOV();
};

