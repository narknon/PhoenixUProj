#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CreatureLookAtTargetEvaluation.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class UCreatureLookAtTargetEvaluation : public UObject {
    GENERATED_BODY()
public:
    UCreatureLookAtTargetEvaluation();
};

