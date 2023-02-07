#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsCapturingSelfActorConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsCapturingSelfActorConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UOptionActorIsCapturingSelfActorConsideration();
};

