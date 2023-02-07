#pragma once
#include "CoreMinimal.h"
#include "AnimDebugInfo.h"
#include "AnimRequestProvider.h"
#include "AnimationTrack.h"
#include "MoveRequestProvider.h"
#include "SkeletalMeshDriver.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblAvaAnimationTaskScratchPad.generated.h"

class AActor;
class USkeletalMeshComponent;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblAvaAnimationTaskScratchPad : public UAblAbilityTaskScratchPad, public ISkeletalMeshDriver, public IAnimRequestProvider, public IMoveRequestProvider, public IAnimDebugInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationTrack AnimationTrack;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> OwningActor;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentBlendWeight;
    
    UAblAvaAnimationTaskScratchPad();
    
    // Fix for true pure virtual functions not being implemented
};

