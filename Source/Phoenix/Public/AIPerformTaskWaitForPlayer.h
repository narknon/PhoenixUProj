#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskWaitForPlayer.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskWaitForPlayer : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ProximityCheckBeforeStopping;
    
    UAIPerformTaskWaitForPlayer();
};

