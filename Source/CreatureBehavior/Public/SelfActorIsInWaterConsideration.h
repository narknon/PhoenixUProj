#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorIsInWaterConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorIsInWaterConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfActorIsInWaterConsideration();
};

