#pragma once
#include "CoreMinimal.h"
#include "EEnemyShieldBreaker.h"
#include "EEnemy_ParryCounterStepDirection.h"
#include "EEnemy_ParryCounterStyle.h"
#include "EEnemy_ParryCounterType.h"
#include "EEnemy_ParryDodgeStyle.h"
#include "EEnemy_ParryResponseType.h"
#include "CreatureCombatAttackParryData.generated.h"

USTRUCT(BlueprintType)
struct FCreatureCombatAttackParryData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnblockableByPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyShieldBreaker UnblockableByNPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryLeadIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryToRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryPerfectBegin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryCounterType ParryCounterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryResponseType ParryResponseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryCounterStepDirection ParryCounterStepDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryCounterStyle ParryCounterStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryDodgeStyle ParryDodgeStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParryAbortDistance;
    
    PHOENIX_API FCreatureCombatAttackParryData();
};

