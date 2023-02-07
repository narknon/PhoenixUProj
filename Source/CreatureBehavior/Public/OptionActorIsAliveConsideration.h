#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsAliveConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsAliveConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UOptionActorIsAliveConsideration();
};

