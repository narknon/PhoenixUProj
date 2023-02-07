#pragma once
#include "CoreMinimal.h"
#include "Enemy_ParryReleaseStartEventData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_ParryReleaseStartEventData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WindowID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToImpact;
    
    PHOENIX_API FEnemy_ParryReleaseStartEventData();
};

