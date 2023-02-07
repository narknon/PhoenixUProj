#pragma once
#include "CoreMinimal.h"
#include "EEnemyShieldBreaker.h"
#include "Enemy_UnblockableData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_UnblockableData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnblockableByPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyShieldBreaker UnblockableLByNPCLevel;
    
    PHOENIX_API FEnemy_UnblockableData();
};

