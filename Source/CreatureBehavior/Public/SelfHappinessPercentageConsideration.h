#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfHappinessPercentageConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfHappinessPercentageConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfHappinessPercentageConsideration();
};

