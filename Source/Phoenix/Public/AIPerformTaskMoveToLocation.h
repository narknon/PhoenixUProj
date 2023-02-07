#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "EPerformTaskSpeedMode.h"
#include "AIPerformTaskMoveToLocation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskMoveToLocation : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskSpeedMode SpeedMode;
    
    UAIPerformTaskMoveToLocation();
};

