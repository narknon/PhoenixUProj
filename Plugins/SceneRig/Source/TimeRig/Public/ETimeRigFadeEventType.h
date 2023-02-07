#pragma once
#include "CoreMinimal.h"
#include "ETimeRigFadeEventType.generated.h"

UENUM(BlueprintType)
enum class ETimeRigFadeEventType : uint8 {
    None,
    InitialFade,
    FinalFade,
};

