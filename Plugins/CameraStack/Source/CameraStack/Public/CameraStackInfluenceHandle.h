#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraStackInfluenceHandle.generated.h"

class UCameraStackVolumePreset;

UCLASS(Blueprintable, Transient)
class CAMERASTACK_API UCameraStackInfluenceHandle : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraStackVolumePreset* Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxBlendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float weight;
    
    UCameraStackInfluenceHandle();
    UFUNCTION(BlueprintCallable)
    void SetInfluenceWeight(float NewWeight);
    
};

