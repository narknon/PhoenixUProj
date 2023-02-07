#pragma once
#include "CoreMinimal.h"
#include "ESpawnAllowedResponse.generated.h"

UENUM(BlueprintType)
enum class ESpawnAllowedResponse : uint8 {
    SAR_ALLOWSPAWN,
    SAR_FAIL_UNREGISTERED_TYPE,
    SAR_FAIL_LOCKED,
    SAR_FAIL_DEAD,
    SAR_FAIL_CONSUMED,
    SAR_FAIL_ALREADY_EXISTS,
    SAR_FAIL_UNKNOWN,
    SAR_MAX UMETA(Hidden),
};

