#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmSimulationFollowInfo.h"
#include "GroundSwarmingDeathVolumes.h"
#include "GroundSwarmingExternalForces.h"
#include "GroundSwarmingFocus.h"
#include "GroundSwarmingForceModifiers.h"
#include "GroundSwarmExternals.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmExternals {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingFocus Follow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingExternalForces ExternalForces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingForceModifiers ForceModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmingDeathVolumes DeathVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGroundSwarmSimulationFollowInfo FollowInfo;
    
    PHOENIX_API FGroundSwarmExternals();
};

