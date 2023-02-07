#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureCirclingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureCirclingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureCirclingConsideration();
};

