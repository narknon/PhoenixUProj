#pragma once
#include "CoreMinimal.h"
#include "EFeedbackAnim.generated.h"

UENUM(BlueprintType)
enum class EFeedbackAnim : uint8 {
    ANIM_PULSE,
    ANIM_ROTATE_CL,
    ANIM_ROTATE_CCL,
    ANIM_BACK_AND_FORTH,
    ANIM_NONE,
    ANIM_MAX UMETA(Hidden),
};

