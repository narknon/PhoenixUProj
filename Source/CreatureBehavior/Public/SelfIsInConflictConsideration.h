#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsInConflictConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsInConflictConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsInConflictConsideration();
};

