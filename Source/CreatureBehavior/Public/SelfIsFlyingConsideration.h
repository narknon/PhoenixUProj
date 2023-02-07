#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsFlyingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsFlyingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsFlyingConsideration();
};

