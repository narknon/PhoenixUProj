#pragma once
#include "CoreMinimal.h"
#include "ESceneRigCameraProxyActor_ValidCameraType.generated.h"

UENUM(BlueprintType)
enum class ESceneRigCameraProxyActor_ValidCameraType : uint8 {
    CheckObstructions,
    AlwaysValid,
    AlwaysInValid,
    ESceneRigCameraProxyActor_MAX UMETA(Hidden),
};

