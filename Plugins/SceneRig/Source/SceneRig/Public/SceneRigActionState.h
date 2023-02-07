#pragma once
#include "CoreMinimal.h"
#include "TimeRigIntervalState.h"
#include "SceneRigActionState.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigActionState : public UTimeRigIntervalState {
    GENERATED_BODY()
public:
    USceneRigActionState();
};

