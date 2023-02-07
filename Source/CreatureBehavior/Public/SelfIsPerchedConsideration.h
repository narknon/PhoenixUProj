#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsPerchedConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsPerchedConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsPerchedConsideration();
};

