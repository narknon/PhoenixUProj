#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CinematicBatchHUD.generated.h"

class APlayerCameraManager;
class UAnimationComponent;
class USceneRig;
class USceneRigPlayer;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCinematicBatchHUD : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* SceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* CameraAnimationComponent;
    
    UCinematicBatchHUD();
    UFUNCTION(BlueprintCallable)
    static void SetFixedFrameRate();
    
    UFUNCTION(BlueprintCallable)
    static float GetCinematicBatchHUDSRLength(USceneRigPlayer* SceneRigPlayer, USceneRig* NewSceneRig, bool bInFrames);
    
    UFUNCTION(BlueprintCallable)
    static UAnimationComponent* GetAnimationComponent(APlayerCameraManager* CameraManager);
    
    UFUNCTION(BlueprintCallable)
    static float GetActiveSRCurrentFrame(USceneRigPlayer* SceneRigPlayer);
    
    UFUNCTION(BlueprintCallable)
    static float GetActiveShotTotalFrames(UAnimationComponent* AnimationComponent);
    
    UFUNCTION(BlueprintCallable)
    static FString GetActiveShotName(UAnimationComponent* AnimationComponent);
    
    UFUNCTION(BlueprintCallable)
    static float GetActiveShotFrame(UAnimationComponent* AnimationComponent);
    
};

