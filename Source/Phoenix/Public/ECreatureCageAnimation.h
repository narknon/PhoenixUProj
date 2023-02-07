#pragma once
#include "CoreMinimal.h"
#include "ECreatureCageAnimation.generated.h"

UENUM(BlueprintType)
enum class ECreatureCageAnimation : uint8 {
    Idle,
    Alert,
    Wounded,
};

