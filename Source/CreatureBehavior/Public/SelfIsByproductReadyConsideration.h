#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsByproductReadyConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsByproductReadyConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsByproductReadyConsideration();
};

