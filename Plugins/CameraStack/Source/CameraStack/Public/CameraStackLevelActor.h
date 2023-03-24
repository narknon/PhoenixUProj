#pragma once
#include "CoreMinimal.h"
#include "CameraPreUpdateTickFunction.h"
#include "CameraStackActor.h"
#include "CameraStackLevelActor.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories)
class CAMERASTACK_API ACameraStackLevelActor : public ACameraStackActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraPreUpdateTickFunction PreUpdateTick;
    
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TLazyObjectPtr<AActor> TargetReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bIsInWorldSpace;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> RuntimeTarget;
    
public:
    ACameraStackLevelActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetRuntimeTarget(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetRuntimeTarget() const;
    
};

