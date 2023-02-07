#pragma once
#include "CoreMinimal.h"
#include "ELerpVolumesApplyWorldContextMode.generated.h"

UENUM(BlueprintType)
enum class ELerpVolumesApplyWorldContextMode : uint8 {
    SetRTPCs,
    SendHermes,
    SetNPCs,
    SetMPCs,
};

