#pragma once
#include "CoreMinimal.h"
#include "ENPC_AbilityChannel.generated.h"

UENUM(BlueprintType)
enum class ENPC_AbilityChannel : uint8 {
    FullBody,
    FullBodyAdditive,
    PartialBody1,
    EmoPartial,
    Facial,
    PartialBody,
    RightArmPartial,
    BlindHead,
    BlindArm,
    Injured,
    Right,
    RightArmPartial2,
    LeftArmPartial,
    ENPC_MAX UMETA(Hidden),
};

