#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "WorldNightDayConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldNightDayConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UWorldNightDayConsideration();
};

