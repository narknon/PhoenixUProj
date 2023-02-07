#pragma once
#include "CoreMinimal.h"
#include "ECameraFixupLayer.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_CameraFixup.generated.h"

class UCameraFixupOperationState;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_CameraFixup : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraFixupLayer Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UCameraFixupOperationState*> FixupOperationStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FirstFrameRefresh;
    
    USceneActionState_CameraFixup();
};

