#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_Interact_DisallowInCombat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCogGroupEvaluation_Interact_DisallowInCombat : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UCogGroupEvaluation_Interact_DisallowInCombat();
};

