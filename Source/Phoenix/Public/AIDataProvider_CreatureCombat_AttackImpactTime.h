#pragma once
#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider_QueryParams.h"
#include "AIDataProvider_CreatureCombat_AttackImpactTime.generated.h"

class UCreatureCombatAttackData;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAIDataProvider_CreatureCombat_AttackImpactTime : public UAIDataProvider_QueryParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* CombatData;
    
    UAIDataProvider_CreatureCombat_AttackImpactTime();
};

