#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_AnimateCurves_FillMode.generated.h"

UENUM(BlueprintType)
enum class ESceneAction_AnimateCurves_FillMode : uint8 {
    Stretch,
    Hold,
    Repeat,
    ESceneAction_AnimateCurves_MAX UMETA(Hidden),
};

