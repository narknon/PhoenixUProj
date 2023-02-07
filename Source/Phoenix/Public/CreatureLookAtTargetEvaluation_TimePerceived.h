#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Float.h"
#include "CreatureLookAtTargetEvaluation_TimePerceived.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_TimePerceived : public UCreatureLookAtTargetEvaluation_Float {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_TimePerceived();
};

