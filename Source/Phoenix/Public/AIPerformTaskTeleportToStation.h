#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskMoveToStation.h"
#include "AIPerformTaskTeleportToStation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskTeleportToStation : public UAIPerformTaskMoveToStation {
    GENERATED_BODY()
public:
    UAIPerformTaskTeleportToStation();
};

