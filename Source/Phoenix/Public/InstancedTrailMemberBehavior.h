#pragma once
#include "CoreMinimal.h"
#include "InstancedTrailMemberScale.h"
#include "InstancedTrailMemberSpawnLerp.h"
#include "InstancedTrailMemberSpin.h"
#include "InstancedTrailMemberVelocity.h"
#include "InstancedTrailPlacement.h"
#include "InstancedTrailMemberBehavior.generated.h"

USTRUCT(BlueprintType)
struct FInstancedTrailMemberBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInstancedTrailPlacement Placement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInstancedTrailMemberScale Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInstancedTrailMemberSpawnLerp SpawnLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSpawnLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInstancedTrailMemberSpin Spin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSpin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInstancedTrailMemberVelocity Velocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseVelocity;
    
    PHOENIX_API FInstancedTrailMemberBehavior();
};

