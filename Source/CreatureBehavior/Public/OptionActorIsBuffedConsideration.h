#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsBuffedConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsBuffedConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EffectIDDBValue;
    
    UOptionActorIsBuffedConsideration();
};

