#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorContextAwareInteractionTypeConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorContextAwareInteractionTypeConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WantedInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsiderActorDistance;
    
    UOptionActorContextAwareInteractionTypeConsideration();
};

