#pragma once
#include "CoreMinimal.h"
#include "EUserConsoleVariableSpecialUsage.generated.h"

UENUM(BlueprintType)
enum class EUserConsoleVariableSpecialUsage : uint8 {
    BlendDomain,
    EnvironmentalGlobalsMPC,
    EnvironmentalGlobalsNPC,
};

