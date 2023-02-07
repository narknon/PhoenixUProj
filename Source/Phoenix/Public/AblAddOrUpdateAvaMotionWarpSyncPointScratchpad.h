#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblAddOrUpdateAvaMotionWarpSyncPointScratchpad.generated.h"

class UAblAvaMotionWarpSyncPointUpdaterScratchpad;
class UAmbulatory_MovementComponent;

UCLASS(Blueprintable, NonTransient)
class UAblAddOrUpdateAvaMotionWarpSyncPointScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAmbulatory_MovementComponent*> MovementComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAvaMotionWarpSyncPointUpdaterScratchpad* UpdaterScratchpad;
    
    UAblAddOrUpdateAvaMotionWarpSyncPointScratchpad();
};

