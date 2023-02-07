#pragma once
#include "CoreMinimal.h"
#include "CameraStackTarget.h"
#include "SceneRigCameraStackTarget.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, EditInlineNew)
class USceneRigCameraStackTarget : public UCameraStackTarget {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTransformProvider> TransformProvider;
    
    USceneRigCameraStackTarget();
};

