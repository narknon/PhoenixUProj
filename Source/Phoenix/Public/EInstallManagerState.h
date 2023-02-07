#pragma once
#include "CoreMinimal.h"
#include "EInstallManagerState.generated.h"

UENUM(BlueprintType)
enum class EInstallManagerState : uint8 {
    Idle,
    Installing,
    InstallAvailable,
};

