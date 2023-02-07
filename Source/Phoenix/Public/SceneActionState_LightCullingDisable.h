#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_LightCullingDisable.generated.h"

UCLASS(Blueprintable)
class USceneActionState_LightCullingDisable : public USceneRigActionState {
    GENERATED_BODY()
public:
    USceneActionState_LightCullingDisable();
};

