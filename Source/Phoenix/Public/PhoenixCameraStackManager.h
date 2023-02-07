#pragma once
#include "CoreMinimal.h"
#include "CameraStackManager.h"
#include "PhoenixCameraStackManager.generated.h"

UCLASS(Blueprintable, NonTransient)
class APhoenixCameraStackManager : public ACameraStackManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableObjectFading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObjectFadeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinObjectFadeOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObjectFadingProbeSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFadeCameraDistanceToAvatar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvatarCapsuleRefRadius;
    
    APhoenixCameraStackManager();
    UFUNCTION(BlueprintCallable)
    void StartFadeToZeroOpacity();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
public:
    UFUNCTION(BlueprintCallable)
    void FinishFadeToZeroOpacity();
    
    UFUNCTION(BlueprintCallable)
    void EnableForceFadeAll();
    
    UFUNCTION(BlueprintCallable)
    void DisableForceFadeAll();
    
};

