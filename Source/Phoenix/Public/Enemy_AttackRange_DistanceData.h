#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EEnemyMovementState.h"
#include "Enemy_AttackRange_DistanceData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_AttackRange_DistanceData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyMovementState EnemyMoveState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    PHOENIX_API FEnemy_AttackRange_DistanceData();
};

