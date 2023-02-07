#pragma once
#include "CoreMinimal.h"
#include "Enemy_IdleData.h"
#include "Enemy_ShuffleData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_ShuffleData : public FEnemy_IdleData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReentryCooldown;
    
    PHOENIX_API FEnemy_ShuffleData();
};

