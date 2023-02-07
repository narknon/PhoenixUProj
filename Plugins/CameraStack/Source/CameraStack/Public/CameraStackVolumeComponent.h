#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CameraStackVolumeInterface.h"
#include "CameraStackVolumeInterfaceProperties.h"
#include "CameraStackVolumeComponent.generated.h"

class UCameraStackVolumePreset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CAMERASTACK_API UCameraStackVolumeComponent : public USceneComponent, public ICameraStackVolumeInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStackVolumeInterfaceProperties VolumeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraStackVolumePreset* VolumePreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCrossBlendSpeed;
    
    UCameraStackVolumeComponent();
    
    // Fix for true pure virtual functions not being implemented
};

