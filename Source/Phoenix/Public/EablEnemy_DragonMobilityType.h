#pragma once
#include "CoreMinimal.h"
#include "EablEnemy_DragonMobilityType.generated.h"

UENUM(BlueprintType)
enum class EablEnemy_DragonMobilityType : uint8 {
    Hover,
    Jump,
    EablEnemy_MAX UMETA(Hidden),
};

