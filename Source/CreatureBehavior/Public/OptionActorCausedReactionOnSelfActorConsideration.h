#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorCausedReactionOnSelfActorConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorCausedReactionOnSelfActorConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeWindowOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeWindowSize;
    
public:
    UOptionActorCausedReactionOnSelfActorConsideration();
};

