#pragma once
#include "CoreMinimal.h"
#include "AblAvaMotionWarpSyncPointUpdater.h"
#include "AblEnemyAttackTargetSyncPointUpdater.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyAttackTargetSyncPointUpdater : public UAblAvaMotionWarpSyncPointUpdater {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredDistanceToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowPositiveTravel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowNegativeTravel;
    
    UAblEnemyAttackTargetSyncPointUpdater();
};

