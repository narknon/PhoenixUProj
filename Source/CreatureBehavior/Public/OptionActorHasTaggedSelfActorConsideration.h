#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorHasTaggedSelfActorConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorHasTaggedSelfActorConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UOptionActorHasTaggedSelfActorConsideration();
};

