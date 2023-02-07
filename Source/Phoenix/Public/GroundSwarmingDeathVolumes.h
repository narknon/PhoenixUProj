#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmingDeathVolume.h"
#include "GroundSwarmingDeathVolumes.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmingDeathVolumes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGroundSwarmingDeathVolume> DeathVolumes;
    
    PHOENIX_API FGroundSwarmingDeathVolumes();
};

