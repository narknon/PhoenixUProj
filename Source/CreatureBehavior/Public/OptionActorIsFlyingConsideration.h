#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsFlyingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsFlyingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UOptionActorIsFlyingConsideration();
};

