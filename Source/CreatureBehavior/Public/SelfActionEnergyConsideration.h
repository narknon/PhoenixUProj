#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActionEnergyConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActionEnergyConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfActionEnergyConsideration();
};

