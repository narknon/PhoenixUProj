#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraStackAnimationRequest.h"
#include "CameraStackAnimationComponent.generated.h"

class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class CAMERASTACK_API UCameraStackAnimationComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCameraStackAnimationRequest CurrentRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCameraStackAnimationRequest LastRequest;
    
public:
    UCameraStackAnimationComponent();
    UFUNCTION(BlueprintCallable)
    void PlayAnimation(const FCameraStackAnimationRequest& InAnimationRequest, const UObject* InRequester);
    
    UFUNCTION(BlueprintCallable)
    void EndAnimation(const UObject* InRequester);
    
};

