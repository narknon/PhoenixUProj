#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureFlyOutOfWaterConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureFlyOutOfWaterConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureFlyOutOfWaterConsideration();
};

