#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Float.h"
#include "CreatureLookAtTargetEvaluation_Speed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_Speed : public UCreatureLookAtTargetEvaluation_Float {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_Speed();
};

