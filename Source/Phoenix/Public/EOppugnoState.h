#pragma once
#include "CoreMinimal.h"
#include "EOppugnoState.generated.h"

UENUM(BlueprintType)
enum class EOppugnoState : uint8 {
    Inactive,
    Wait,
    Pull,
    Hold,
    ThrowWait,
    Throw,
    EndWait,
    End,
};

