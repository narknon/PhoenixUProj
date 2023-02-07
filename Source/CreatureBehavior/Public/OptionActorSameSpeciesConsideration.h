#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorSameSpeciesConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorSameSpeciesConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UOptionActorSameSpeciesConsideration();
};

