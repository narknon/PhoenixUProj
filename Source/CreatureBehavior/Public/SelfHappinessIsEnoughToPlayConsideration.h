#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfHappinessIsEnoughToPlayConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfHappinessIsEnoughToPlayConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfHappinessIsEnoughToPlayConsideration();
};

