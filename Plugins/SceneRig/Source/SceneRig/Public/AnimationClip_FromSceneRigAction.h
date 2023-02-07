#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "AnimationClip_FromSceneRigAction.generated.h"

class USceneRigProxyActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimationClip_FromSceneRigAction : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProxyActor* Actor;
    
    UAnimationClip_FromSceneRigAction();
};

