#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsCustomBlendDomainBucket.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsCustomBlendDomainBucket : uint8 {
    First,
    Normal,
    Last,
    Custom,
};

