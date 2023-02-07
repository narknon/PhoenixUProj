#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Float.h"
#include "CreatureLookAtTargetEvaluation_Distance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_Distance : public UCreatureLookAtTargetEvaluation_Float {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_Distance();
};

