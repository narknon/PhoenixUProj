#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraStackVolumeOperationSettings.h"
#include "CameraStackVolumePreset.generated.h"

class UCameraStackVolumePreset;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackVolumePreset : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCameraStackVolumeOperationSettings> VolumeOperations;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UCameraStackVolumePreset*> StyleOverrides;
    
public:
    UCameraStackVolumePreset();
};

