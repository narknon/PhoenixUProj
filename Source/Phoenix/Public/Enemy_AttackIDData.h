#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Enemy_AttackIDData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_AttackIDData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo EnemyDatabaseIDs;
    
    PHOENIX_API FEnemy_AttackIDData();
};

