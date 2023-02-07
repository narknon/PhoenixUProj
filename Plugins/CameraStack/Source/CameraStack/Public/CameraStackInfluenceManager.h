#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraStackInfluenceManager.generated.h"

class UCameraStackInfluenceHandle;
class UCameraStackVolumePreset;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackInfluenceManager : public UObject {
    GENERATED_BODY()
public:
    UCameraStackInfluenceManager();
    UFUNCTION(BlueprintCallable)
    static void UnregisterInfluence(UCameraStackInfluenceHandle* InHandle);
    
    UFUNCTION(BlueprintCallable)
    static UCameraStackInfluenceHandle* RegisterInfluence(UCameraStackVolumePreset* InPreset, int32 Priority, float MaxBlendSpeed);
    
};

