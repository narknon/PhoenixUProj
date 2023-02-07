#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfCanBeCapturedConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCanBeCapturedConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfCanBeCapturedConsideration();
};

