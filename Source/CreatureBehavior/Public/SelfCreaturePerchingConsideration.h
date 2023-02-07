#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreaturePerchingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreaturePerchingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreaturePerchingConsideration();
};

