#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsAwareConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsAwareConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsAwareConsideration();
};

