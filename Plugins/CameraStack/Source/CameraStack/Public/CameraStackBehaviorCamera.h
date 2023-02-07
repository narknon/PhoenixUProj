#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorCamera.generated.h"

class AActor;
class USceneComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCamera : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainArmRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainArmOrigin;
    
    UCameraStackBehaviorCamera();
    UFUNCTION(BlueprintCallable)
    void SetSourceCameraComponent(USceneComponent* InSourceCamera, const bool bInIsValidOverDuration);
    
    UFUNCTION(BlueprintCallable)
    void SetSourceCamera(AActor* InSourceCamera, const bool bInIsValidOverDuration);
    
};

