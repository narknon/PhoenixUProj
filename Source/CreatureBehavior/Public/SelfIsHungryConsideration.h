#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsHungryConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsHungryConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsHungryConsideration();
};

