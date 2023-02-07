#pragma once
#include "CoreMinimal.h"
#include "EWeatherDecalParameterType.generated.h"

UENUM(BlueprintType)
enum class EWeatherDecalParameterType : uint8 {
    EnvGlobals,
    MID,
    MPC,
    NPC,
    SystemMPC,
    SystemNPC,
    RTPC,
    SceneRigEnvGlobals,
};

