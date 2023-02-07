#pragma once
#include "CoreMinimal.h"
#include "Enemy_TargetSense_FOVSet.h"
#include "Enemy_TargetSense_FOV.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TargetSense_FOV {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense_FOVSet Standard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense_FOVSet Disillusionment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense_FOVSet Invisible;
    
    PHOENIX_API FEnemy_TargetSense_FOV();
};

