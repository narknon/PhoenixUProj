#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureCanForageConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureCanForageConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureCanForageConsideration();
};

