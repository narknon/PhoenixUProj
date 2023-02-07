#pragma once
#include "CoreMinimal.h"
#include "AnimSequencerInstance.h"
#include "AnimInstance_RetrieveActorTransform.h"
#include "AnimationRequestLayerHost.h"
#include "SceneRigAnimInstance.generated.h"

class UAnimAsset_TickAssetPlayerProxy;

UCLASS(Blueprintable, NonTransient)
class SCENERIG_API USceneRigAnimInstance : public UAnimSequencerInstance, public IAnimInstance_RetrieveActorTransform, public IAnimationRequestLayerHost {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAnimAsset_TickAssetPlayerProxy* TickAssetPlayerProxy;
    
public:
    USceneRigAnimInstance();
    
    // Fix for true pure virtual functions not being implemented
};

