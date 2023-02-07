#pragma once
#include "CoreMinimal.h"
#include "EnemyApparateActor_Movement.generated.h"

UENUM(BlueprintType)
enum class EnemyApparateActor_Movement : uint8 {
    ToLoc,
    ToTarget,
    EnemyApparateActor_MAX UMETA(Hidden),
};

