#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityStartResult.generated.h"

UENUM(BlueprintType)
enum class EAblAbilityStartResult : uint8 {
    InvalidTarget,
    FailedCustomCheck,
    CooldownNotExpired,
    CannotInterruptCurrentAbility,
    NotAllowedAsPassive,
    PassiveMaxStacksReached,
    InternalSystemsError,
    AsyncProcessing,
    ForwardedToServer,
    InvalidParameter,
    Success,
};

