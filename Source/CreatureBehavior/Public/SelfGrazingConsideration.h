#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfGrazingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfGrazingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfGrazingConsideration();
};

