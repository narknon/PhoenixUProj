#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_AnimatedLightControllerComponent.generated.h"

class UAnimatedLightClusterComponent;

UCLASS(Blueprintable)
class USceneActionState_AnimatedLightControllerComponent : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAnimatedLightClusterComponent> AnimatedLightComponent;
    
    USceneActionState_AnimatedLightControllerComponent();
};

