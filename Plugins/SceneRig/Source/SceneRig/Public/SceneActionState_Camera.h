#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneRigBakeSequence.h"
#include "SceneActionState_Camera.generated.h"

class AActor;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Camera : public USceneRigActionState, public ISceneRigBakeSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CameraActor;
    
    USceneActionState_Camera();
    
    // Fix for true pure virtual functions not being implemented
};

