#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_AnimateCurves_BlendMode.generated.h"

UENUM(BlueprintType)
enum class ESceneAction_AnimateCurves_BlendMode : uint8 {
    Replace,
    Multiply,
    Additive,
    ESceneAction_AnimateCurves_MAX UMETA(Hidden),
};

