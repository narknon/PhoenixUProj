#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIAttackState.h"
#include "EnemyAIAttackDistTableData.h"
#include "EnemyAIAttackDistTableDataContainer.generated.h"

USTRUCT(BlueprintType)
struct FEnemyAIAttackDistTableDataContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIAttackState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyAIAttackDistTableData Data;
    
    PHOENIX_API FEnemyAIAttackDistTableDataContainer();
};

