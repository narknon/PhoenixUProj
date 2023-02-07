#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Bool.h"
#include "CreatureLookAtTargetEvaluation_IsParent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_IsParent : public UCreatureLookAtTargetEvaluation_Bool {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_IsParent();
};

