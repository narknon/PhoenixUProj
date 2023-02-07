#pragma once
#include "CoreMinimal.h"
#include "ESceneRigStageRoleType.generated.h"

UENUM()
enum class ESceneRigStageRoleType : int8 {
    NONE,
    Foreground,
    Background,
    Extra,
    Prop,
};

