#pragma once
#include "CoreMinimal.h"
#include "EAvatarPresetType.generated.h"

UENUM(BlueprintType)
enum class EAvatarPresetType : uint8 {
    EYEBROWCOLOR,
    EYEBROWSHAPE,
    EYECOLOR,
    FACEMARKING0,
    FACEMARKING1,
    FACEMARKING2,
    FACEMARKING3,
    MAKEUP_LIP,
    MAKEUP_EYELINER,
    MAKEUP_EYESHADOW,
    MAKEUP_BLUSH,
    HAIRCOLOR,
    HAIRSTYLE,
    HEADSTYLE,
    SKINCOLOR,
};

