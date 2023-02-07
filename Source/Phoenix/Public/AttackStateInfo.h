#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackThreatState.h"
#include "AttackStateInfo.generated.h"

USTRUCT(BlueprintType)
struct FAttackStateInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnblockable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AttackThreatState AttackThreatState;
    
    PHOENIX_API FAttackStateInfo();
};

