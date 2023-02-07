#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGroundSwarmMemberState.h"
#include "EGroundSwarmingKillEventDeathLeapCollisionType.h"
#include "SwarmMemberDesiredDeathState.generated.h"

USTRUCT(BlueprintType)
struct FSwarmMemberDesiredDeathState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGroundSwarmMemberState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DeathLeapImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathLeapImpulseVariancePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGroundSwarmingKillEventDeathLeapCollisionType DeathLeapCheckForActorCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DeathLeapAlignTowardsCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeathLeapAlignTowardsCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StateTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStateTimeout;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Instigator;
    
public:
    PHOENIX_API FSwarmMemberDesiredDeathState();
};

