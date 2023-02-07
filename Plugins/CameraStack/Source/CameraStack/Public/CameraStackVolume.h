#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "CameraStackVolumeInterface.h"
#include "CameraStackVolumeInterfaceProperties.h"
#include "CameraStackVolume.generated.h"

class UCameraStackVolumeComponent;
class UCameraStackVolumePreset;

UCLASS(Blueprintable, MinimalAPI)
class ACameraStackVolume : public AVolume, public ICameraStackVolumeInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStackVolumeInterfaceProperties VolumeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackVolumeComponent* VolumeComponent;
    
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
    
    ACameraStackVolume();
    
    // Fix for true pure virtual functions not being implemented
};

