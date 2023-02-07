#pragma once
#include "CoreMinimal.h"
#include "EPostDeathCleanupEffect.h"
#include "EPostDeathCleanupMode.h"
#include "EPostDeathSortingMode.h"
#include "PostDeath_Params.generated.h"

USTRUCT(BlueprintType)
struct FPostDeath_Params {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostDeathCleanupEffect CleanUpEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostDeathCleanupMode CleanUpMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPostDeathSortingMode SortingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BatchSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxAllowedDeadNPCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinAllowedDeadNPCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBetweenBatches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimerModeDelay;
    
    PHOENIX_API FPostDeath_Params();
};

