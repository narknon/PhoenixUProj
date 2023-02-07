#pragma once
#include "CoreMinimal.h"
#include "Enemy_Idle.h"
#include "Enemy_IdleBreak.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_IdleBreak {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_Idle Data;
    
    PHOENIX_API FEnemy_IdleBreak();
};

