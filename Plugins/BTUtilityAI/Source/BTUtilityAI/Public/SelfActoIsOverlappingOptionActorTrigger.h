#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActoIsOverlappingOptionActorTrigger.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActoIsOverlappingOptionActorTrigger : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TriggerName;
    
public:
    USelfActoIsOverlappingOptionActorTrigger();
};

