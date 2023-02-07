#pragma once
#include "CoreMinimal.h"
#include "EnemyAIAttackDistData.generated.h"

USTRUCT(BlueprintType)
struct FEnemyAIAttackDistData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttackDesperationEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttackDesperationMinRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttackDesperationMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttackDesperationNotInRangeTime;
    
    PHOENIX_API FEnemyAIAttackDistData();
};

