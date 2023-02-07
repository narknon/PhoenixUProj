#pragma once
#include "CoreMinimal.h"
#include "EEnemySpiderAISpawnType.generated.h"

UENUM(BlueprintType)
enum class EEnemySpiderAISpawnType : uint8 {
    None,
    UpFromGround,
    FallFromSky,
    DescentOnWeb,
    WakeUp,
    Tumble,
    TumbleAndDie,
};

