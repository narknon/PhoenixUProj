#pragma once
#include "CoreMinimal.h"
#include "EMenuReaderInterruptType.generated.h"

UENUM(BlueprintType)
enum class EMenuReaderInterruptType : uint8 {
    InterruptAll,
    InterruptSelf,
    InterruptSpecifiedOwner,
    InterruptNone,
};

