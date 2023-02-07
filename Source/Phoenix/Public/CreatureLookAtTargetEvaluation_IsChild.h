#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Bool.h"
#include "CreatureLookAtTargetEvaluation_IsChild.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_IsChild : public UCreatureLookAtTargetEvaluation_Bool {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_IsChild();
};

