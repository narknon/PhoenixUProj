#pragma once
#include "CoreMinimal.h"
#include "CameraStackOperationState.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_CameraStackModification.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_CameraStackModification : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCameraStackOperationState> OperationStates;
    
public:
    USceneActionState_CameraStackModification();
};

