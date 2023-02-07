#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorCore.h"
#include "CameraStackBehaviorCore_Actor.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCore_Actor : public UCameraStackBehaviorCore {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TransformActor;
    
public:
    UCameraStackBehaviorCore_Actor();
    UFUNCTION(BlueprintCallable)
    void SetTransformActor(AActor* InTransformActor);
    
};

