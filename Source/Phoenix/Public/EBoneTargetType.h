#pragma once
#include "CoreMinimal.h"
#include "EBoneTargetType.generated.h"

UENUM(BlueprintType)
enum class EBoneTargetType : uint8 {
    None,
    Default,
    Biped,
    Dugbog,
    Spider,
    Wolf,
    Dragon,
};

