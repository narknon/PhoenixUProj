#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsPregnantConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsPregnantConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsPregnantConsideration();
};

