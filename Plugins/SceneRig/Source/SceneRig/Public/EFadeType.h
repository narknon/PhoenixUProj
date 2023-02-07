#pragma once
#include "CoreMinimal.h"
#include "EFadeType.generated.h"

UENUM(BlueprintType)
enum class EFadeType : uint8 {
    FadeIn,
    FadeOut,
    HoldFade,
    Manual,
};

