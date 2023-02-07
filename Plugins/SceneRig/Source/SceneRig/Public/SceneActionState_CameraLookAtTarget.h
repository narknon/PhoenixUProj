#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_CameraLookAtTarget.generated.h"

class ACameraStackLookAtTargetActor;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_CameraLookAtTarget : public USceneRigActionState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACameraStackLookAtTargetActor* LookAtTargetActor;
    
public:
    USceneActionState_CameraLookAtTarget();
};

