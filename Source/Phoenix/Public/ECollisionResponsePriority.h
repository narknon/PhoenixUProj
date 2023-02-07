#pragma once
#include "CoreMinimal.h"
#include "ECollisionResponsePriority.generated.h"

UENUM(BlueprintType)
enum class ECollisionResponsePriority : uint8 {
    Normal,
    InStation,
    CollisionResponse,
    PerformTask,
    Blueprint,
    Cinematic,
    Hidden,
};

