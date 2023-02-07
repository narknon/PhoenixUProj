#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorAttackPatternWeightConsideration.generated.h"

class UCreatureCombatAttackData;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorAttackPatternWeightConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* AttackData;
    
    USelfActorAttackPatternWeightConsideration();
};

