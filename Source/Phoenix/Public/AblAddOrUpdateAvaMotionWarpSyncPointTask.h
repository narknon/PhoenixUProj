#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblAddOrUpdateAvaMotionWarpSyncPointTask.generated.h"

class UAblAvaMotionWarpSyncPointUpdater;

UCLASS(Blueprintable, EditInlineNew)
class UAblAddOrUpdateAvaMotionWarpSyncPointTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SyncPointName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblAvaMotionWarpSyncPointUpdater* SyncPointUpdater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateSyncPointOnTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemoveSyncPointOnEndOfTask;
    
    UAblAddOrUpdateAvaMotionWarpSyncPointTask();
};

