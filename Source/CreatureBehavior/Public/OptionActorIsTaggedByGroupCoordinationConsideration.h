#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsTaggedByGroupCoordinationConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsTaggedByGroupCoordinationConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UOptionActorIsTaggedByGroupCoordinationConsideration();
};

