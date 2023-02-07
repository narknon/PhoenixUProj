#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapSphereSelectionActorEventType.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapSphereSelectionActorEventType : uint8 {
    ActorAdded,
    ActorRemoved,
};

