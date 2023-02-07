#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorLastInteractionTimeConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorLastInteractionTimeConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindowOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindowSize;
    
    UOptionActorLastInteractionTimeConsideration();
};

