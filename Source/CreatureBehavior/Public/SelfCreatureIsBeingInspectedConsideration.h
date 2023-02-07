#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureIsBeingInspectedConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureIsBeingInspectedConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureIsBeingInspectedConsideration();
};

