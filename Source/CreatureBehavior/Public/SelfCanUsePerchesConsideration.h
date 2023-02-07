#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCanUsePerchesConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCanUsePerchesConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCanUsePerchesConsideration();
};

