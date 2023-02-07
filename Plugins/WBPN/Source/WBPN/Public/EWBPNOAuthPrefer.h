#pragma once
#include "CoreMinimal.h"
#include "EWBPNOAuthPrefer.generated.h"

UENUM(BlueprintType)
enum class EWBPNOAuthPrefer : uint8 {
    NONE,
    SIGNIN,
    REGISTER,
};

