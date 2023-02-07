#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionEnemyMoveHit.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyMoveHit : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyTriggerOnGroundMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnGroundRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnAirRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreHitAfterDeath;
    
public:
    UAblBranchConditionEnemyMoveHit();
};

