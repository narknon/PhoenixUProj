#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfLazinessConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfLazinessConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfLazinessConsideration();
};

