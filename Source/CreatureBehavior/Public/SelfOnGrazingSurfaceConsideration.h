#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfOnGrazingSurfaceConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfOnGrazingSurfaceConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    USelfOnGrazingSurfaceConsideration();
};

