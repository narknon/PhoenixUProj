#pragma once
#include "CoreMinimal.h"
#include "Enemy_TargetSense_Remember.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TargetSense_Remember {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RememberMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOSTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOVAndHearingTime;
    
    PHOENIX_API FEnemy_TargetSense_Remember();
};

