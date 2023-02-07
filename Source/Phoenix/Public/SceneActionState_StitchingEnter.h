#pragma once
#include "CoreMinimal.h"
#include "AnimDebugInfo.h"
#include "AnimRequestProvider.h"
#include "AnimationTrack.h"
#include "MoveRequestProvider.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_StitchingEnter.generated.h"

class AActor;
class UAble_AnimInstance;
class UAnimSequence;
class UAnimationComponent;
class UCustomizableCharacterComponent;
class USkeletalMeshComponent;
class USplineComponent;

UCLASS(Blueprintable)
class USceneActionState_StitchingEnter : public USceneRigObjectActionState, public IAnimRequestProvider, public IMoveRequestProvider, public IAnimDebugInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack AnimationTrack;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* Path;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequence*> AnimSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* EntryAnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* CurrAnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* PrevAnimSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAble_AnimInstance* AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CCC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldBeRegistered;
    
    USceneActionState_StitchingEnter();
    
    // Fix for true pure virtual functions not being implemented
};

