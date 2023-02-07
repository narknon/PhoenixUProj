#pragma once
#include "CoreMinimal.h"
#include "EAmbientCreatureSpawnVolumeType.generated.h"

UENUM()
enum class EAmbientCreatureSpawnVolumeType : int32 {
    Spawn,
    Exclude,
    SuppressAndExclude,
};

