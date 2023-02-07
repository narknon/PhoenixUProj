#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureGroomingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureGroomingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureGroomingConsideration();
};

