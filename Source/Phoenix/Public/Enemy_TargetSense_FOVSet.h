#pragma once
#include "CoreMinimal.h"
#include "Enemy_TargetSense_FOVParams.h"
#include "Enemy_TargetSense_FOVSet.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TargetSense_FOVSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense_FOVParams Aware;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense_FOVParams Alert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense_FOVParams Attack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisallowTimeWhenApplied;
    
    PHOENIX_API FEnemy_TargetSense_FOVSet();
};

