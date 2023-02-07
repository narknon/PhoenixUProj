#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCreatureWantsNurturingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureWantsNurturingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCreatureWantsNurturingConsideration();
};

