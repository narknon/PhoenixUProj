#pragma once
#include "CoreMinimal.h"
#include "ESceneRigAnimationTrackConstraintMode.generated.h"

UENUM(BlueprintType)
enum class ESceneRigAnimationTrackConstraintMode : uint8 {
    ConstrainComponent,
    ConstrainActor,
};

