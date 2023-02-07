#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_PlaySceneRigInitializeType.generated.h"

UENUM()
enum class ESceneAction_PlaySceneRigInitializeType : int8 {
    OnStartOfSceneRig,
    OnStartOfAction,
    ESceneAction_MAX UMETA(Hidden),
};

