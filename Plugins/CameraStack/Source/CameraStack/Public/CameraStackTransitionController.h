#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "CameraStackTransitionController.generated.h"

class ACameraStackActor;
class APlayerController;
class UCameraStackSettings;

UCLASS(Blueprintable)
class CAMERASTACK_API ACameraStackTransitionController : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraStackSettings* StackSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACameraStackActor> CameraActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConstrainAspectRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRelativeToArmRotation;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACameraStackActor* CameraStackActor;
    
public:
    ACameraStackTransitionController();
    UFUNCTION(BlueprintCallable)
    void TransitionToCameraAndTargetLocation(AActor* InCameraActor, FVector InTargetLocation, float InTransitionDuration, float InDelay);
    
    UFUNCTION(BlueprintCallable)
    void TransitionToCameraAndTargetActor(AActor* InCameraActor, AActor* InTargetLocationActor, float InTransitionDuration, float InDelay);
    
    UFUNCTION(BlueprintCallable)
    void TransitionToCamera(AActor* InCameraActor, float InTransitionDuration, float InDelay);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    APlayerController* GetPlayerController() const;
    
};

