#pragma once
#include "CoreMinimal.h"
#include "EHelperState.generated.h"

UENUM(BlueprintType)
enum class EHelperState : uint8 {
    IDLE,
    START,
    DEPLOY,
    DEPLOY_TURN,
    RUN,
    ATTRACT,
    POP_OUT,
    END,
};

