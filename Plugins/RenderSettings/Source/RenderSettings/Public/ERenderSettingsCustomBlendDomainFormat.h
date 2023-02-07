#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsCustomBlendDomainFormat.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsCustomBlendDomainFormat : uint8 {
    Default,
    ZeroToOne,
    NoIfZero,
    YesIfOne,
    OnlyNoIfZero,
    OnlyYesIfOne,
    OnlyNoIfNotOne,
    OnlyYesIfNotZero,
    HideIfDefault,
    Hide,
};

