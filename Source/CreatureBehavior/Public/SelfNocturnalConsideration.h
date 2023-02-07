#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfNocturnalConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfNocturnalConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfNocturnalConsideration();
};

