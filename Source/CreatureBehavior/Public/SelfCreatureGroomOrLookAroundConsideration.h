#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureGroomOrLookAroundConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureGroomOrLookAroundConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureGroomOrLookAroundConsideration();
};

