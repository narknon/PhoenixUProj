#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsCapturedConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsCapturedConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsCapturedConsideration();
};

