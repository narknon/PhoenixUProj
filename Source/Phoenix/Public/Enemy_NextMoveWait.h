#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackUpdateState.h"
#include "Enemy_NextMoveWait.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_NextMoveWait {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AttackUpdateState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    PHOENIX_API FEnemy_NextMoveWait();
};

