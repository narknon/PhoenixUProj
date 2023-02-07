#pragma once
#include "CoreMinimal.h"
#include "EAcknowledgementRuleType.generated.h"

UENUM(BlueprintType)
enum class EAcknowledgementRuleType : uint8 {
    Time,
    Event,
    Ambient,
    COUNT,
};

