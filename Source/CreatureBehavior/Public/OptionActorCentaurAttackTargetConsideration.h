#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorCentaurAttackTargetConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorCentaurAttackTargetConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttackDescriptorName;
    
    UOptionActorCentaurAttackTargetConsideration();
};

