#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfHerdingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfHerdingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfHerdingConsideration();
};

