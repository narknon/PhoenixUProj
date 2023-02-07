#pragma once
#include "CoreMinimal.h"
#include "TimeRigCoordinate.h"
#include "SceneRigActionState.h"
#include "SceneActionState_EmbeddedSceneRig.generated.h"

class USceneRig;
class USceneRigInstanceContext;
class UTimeRigInstanceContext;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_EmbeddedSceneRig : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* SceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigInstanceContext* InstanceContext;
    
    USceneActionState_EmbeddedSceneRig();
    UFUNCTION(BlueprintCallable)
    void OnNamedEventChanged(FTimeRigCoordinate PreviousValue, FTimeRigCoordinate CurrentValue, UTimeRigInstanceContext* InContext);
    
};

