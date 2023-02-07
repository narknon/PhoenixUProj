#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorInteractionTypeConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorInteractionTypeConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WantedInteraction;
    
    UOptionActorInteractionTypeConsideration();
};

