#pragma once
#include "CoreMinimal.h"
#include "EFeatureInstallState.generated.h"

UENUM(BlueprintType)
enum class EFeatureInstallState : uint8 {
    NotSupported,
    NotInstalled,
    PartiallyInstalled,
    Installing,
    Installed,
};

