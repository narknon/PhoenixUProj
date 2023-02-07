#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Bool.h"
#include "CreatureLookAtTargetEvaluation_IsPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_IsPlayer : public UCreatureLookAtTargetEvaluation_Bool {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation_IsPlayer();
};

