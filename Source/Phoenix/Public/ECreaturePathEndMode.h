#pragma once
#include "CoreMinimal.h"
#include "ECreaturePathEndMode.generated.h"

UENUM(BlueprintType)
enum class ECreaturePathEndMode : uint8 {
    Stop,
    KeepSpeed,
};

