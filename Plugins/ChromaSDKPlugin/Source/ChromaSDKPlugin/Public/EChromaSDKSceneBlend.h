#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKSceneBlend.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKSceneBlend {
    enum Type {
        SB_None,
        SB_Invert,
        SB_Threshold,
        SB_Lerp,
        SB_MAX UMETA(Hidden),
    };
}

