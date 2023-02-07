#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "AnyPerchAvailableInRangeConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnyPerchAvailableInRangeConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UAnyPerchAvailableInRangeConsideration();
};

