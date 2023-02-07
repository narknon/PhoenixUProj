#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskTeleportToLocation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskTeleportToLocation : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UAIPerformTaskTeleportToLocation();
};

