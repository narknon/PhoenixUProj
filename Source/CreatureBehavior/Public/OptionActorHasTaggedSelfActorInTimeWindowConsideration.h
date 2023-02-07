#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorHasTaggedSelfActorInTimeWindowConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorHasTaggedSelfActorInTimeWindowConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FalloffStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FalloffSize;
    
    UOptionActorHasTaggedSelfActorInTimeWindowConsideration();
};

