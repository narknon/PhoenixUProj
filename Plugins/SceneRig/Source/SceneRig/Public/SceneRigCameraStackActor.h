#pragma once
#include "CoreMinimal.h"
#include "AnimatedFloatPropertyDriver.h"
#include "AnimatedIntegerPropertyDriver.h"
#include "CameraStackActor.h"
#include "SRCameraFocusSettings.h"
#include "SRCameraPostProcessSettings.h"
#include "SceneRigCameraStackActor.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable, CollapseCategories)
class ASceneRigCameraStackActor : public ACameraStackActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EyeSocketName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSRCameraFocusSettings FocusSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSRCameraPostProcessSettings RenderFeatures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimatedIntegerPropertyDriver LODDetailMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver CurrentFocalLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver CurrentAperture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver CurrentFocusDistance;
    
public:
    ASceneRigCameraStackActor();
};

