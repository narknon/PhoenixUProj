#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCanFlyConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCanFlyConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCanFlyConsideration();
};

