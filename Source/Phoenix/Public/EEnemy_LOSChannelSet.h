#pragma once
#include "CoreMinimal.h"
#include "EEnemy_LOSChannelSet.generated.h"

UENUM(BlueprintType)
enum class EEnemy_LOSChannelSet : uint8 {
    All,
    Static,
    StaticAndDynamic,
    EEnemy_MAX UMETA(Hidden),
};

