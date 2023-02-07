#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsCombatReadyConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsCombatReadyConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsCombatReadyConsideration();
};

