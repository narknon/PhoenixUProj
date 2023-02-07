#pragma once
#include "CoreMinimal.h"
#include "ActiveCameraActor.h"
#include "AnimatedFloatPropertyDriver.h"
#include "AnimatedIntegerPropertyDriver.h"
#include "CineCameraActor.h"
#include "Camera/CameraActor.h"
#include "SRCameraFocusSettings.h"
#include "SRCameraPostProcessSettings.h"
#include "SceneRigCamera.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class SCENERIG_API ASceneRigCamera : public ACameraActor, public IActiveCameraActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraLookatTrackingSettings LookatTrackingSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CameraSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSRCameraFocusSettings FocusSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSRCameraPostProcessSettings RenderFeatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedIntegerPropertyDriver LODDetailMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver CurrentFocalLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver CurrentAperture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver CurrentFocusDistance;
    
public:
    ASceneRigCamera();
    
    // Fix for true pure virtual functions not being implemented
};

