#pragma once
#include "CoreMinimal.h"
#include "ECreaturePerceptionVolumeType.generated.h"

UENUM()
enum class ECreaturePerceptionVolumeType : int32 {
    AlwaysPerceiveInside,
    KeepPerceptionInside,
};

