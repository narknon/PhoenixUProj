#pragma once
#include "CoreMinimal.h"
#include "Enemy_Idle.h"
#include "Enemy_Shuffle.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_Shuffle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SupportedDirections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_Idle Data;
    
    PHOENIX_API FEnemy_Shuffle();
};

