#pragma once
#include "CoreMinimal.h"
#include "EWandLinkMiniGameType.generated.h"

UENUM(BlueprintType)
enum class EWandLinkMiniGameType : uint8 {
    StickAndButton,
    ButtonMash,
    NewButtonMash,
};

