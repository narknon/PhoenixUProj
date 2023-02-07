#pragma once
#include "CoreMinimal.h"
#include "ELoginResponse.generated.h"

UENUM(BlueprintType)
enum class ELoginResponse : uint8 {
    SuccessNoWWID,
    SuccessAndWWID,
    Incomplete,
    SilentFailure,
    Invalid,
    Failure,
};

