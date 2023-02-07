#pragma once
#include "CoreMinimal.h"
#include "AnimDebugInfo.h"
#include "AnimRequestProvider.h"
#include "AnimationTrack.h"
#include "MoveRequestProvider.h"
#include "TimeRigParentElement.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_Animation.generated.h"

class UAnimationComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Animation : public USceneRigObjectActionState, public IAnimRequestProvider, public IMoveRequestProvider, public ISceneRigBakeSequence, public IAnimDebugInfo, public ITimeRigParentElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack AnimationTrack;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentBlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CurrentlyInBlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CurrentlyInBlendOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldBeRegistered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    USceneActionState_Animation();
    
    // Fix for true pure virtual functions not being implemented
};

