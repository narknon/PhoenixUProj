#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsOffspringConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsOffspringConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsOffspringConsideration();
};

