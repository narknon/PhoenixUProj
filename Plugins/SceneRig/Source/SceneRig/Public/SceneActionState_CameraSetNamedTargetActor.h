#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_CameraSetNamedTargetActor.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_CameraSetNamedTargetActor : public USceneRigActionState {
    GENERATED_BODY()
public:
    USceneActionState_CameraSetNamedTargetActor();
};

