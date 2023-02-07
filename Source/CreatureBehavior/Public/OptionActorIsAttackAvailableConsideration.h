#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsAttackAvailableConsideration.generated.h"

class UCreatureCombatAttackData;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsAttackAvailableConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* AttackData;
    
    UOptionActorIsAttackAvailableConsideration();
};

