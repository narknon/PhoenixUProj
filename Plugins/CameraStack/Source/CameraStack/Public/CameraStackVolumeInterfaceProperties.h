#pragma once
#include "CoreMinimal.h"
#include "CameraStackVolumeInterfaceProperties.generated.h"

class UCameraStackVolumePreset;

USTRUCT(BlueprintType)
struct FCameraStackVolumeInterfaceProperties {
    GENERATED_BODY()
public:
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
    
    CAMERASTACK_API FCameraStackVolumeInterfaceProperties();
};

