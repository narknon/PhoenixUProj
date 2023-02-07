#pragma once
#include "CoreMinimal.h"
#include "ESceneRigAnimationRootBlendMode.generated.h"

UENUM(BlueprintType)
enum class ESceneRigAnimationRootBlendMode : uint8 {
    BlendRootWithAnimation,
    DoNotBlendRoot,
};

