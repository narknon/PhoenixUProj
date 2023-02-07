#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryType.h"
#include "Enemy_ParryFiredEventData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_ParryFiredEventData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WindowID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryType ParryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToImpact;
    
    PHOENIX_API FEnemy_ParryFiredEventData();
};

