#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_SlaveToSpline.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_SlaveToSpline : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
public:
    USceneActionState_SlaveToSpline();
};

