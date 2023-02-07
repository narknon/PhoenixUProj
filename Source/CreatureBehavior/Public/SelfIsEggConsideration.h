#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsEggConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsEggConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsEggConsideration();
};

