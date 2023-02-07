#pragma once
#include "CoreMinimal.h"
#include "ESceneRigProxyActor_PlatformHide.generated.h"

UENUM()
enum class ESceneRigProxyActor_PlatformHide : int8 {
    None,
    SwitchOnly,
    LastGenAndSwitch,
    ESceneRigProxyActor_MAX UMETA(Hidden),
};

