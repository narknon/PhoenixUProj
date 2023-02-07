#pragma once
#include "CoreMinimal.h"
#include "EStationExitCallBack.generated.h"

UENUM(BlueprintType)
enum class EStationExitCallBack : uint8 {
    InteractionCompleteCallback,
    StartApparateCallback,
    DestructionCallback,
    DoNothingCallback,
    DoNothingCallbackAndClear,
};

