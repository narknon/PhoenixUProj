#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsAdultConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsAdultConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfIsAdultConsideration();
};

