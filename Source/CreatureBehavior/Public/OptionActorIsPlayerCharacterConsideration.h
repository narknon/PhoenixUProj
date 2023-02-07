#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsPlayerCharacterConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsPlayerCharacterConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UOptionActorIsPlayerCharacterConsideration();
};

