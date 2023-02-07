#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_ComponentOwnerInterface.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "SkeletalMeshDriver.h"
#include "SceneRigActionState.h"
#include "SceneRigObjectActionState.generated.h"

class UObject;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigObjectActionState : public USceneRigActionState, public ISkeletalMeshDriver, public IAnimationArchitect_TagProviderInterface, public IAnimationArchitect_ComponentOwnerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> ActionObject;
    
    USceneRigObjectActionState();
    
    // Fix for true pure virtual functions not being implemented
};

