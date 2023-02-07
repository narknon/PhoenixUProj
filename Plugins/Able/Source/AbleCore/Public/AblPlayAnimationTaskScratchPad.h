#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "OnPlayAnimationPlayedDelegate.h"
#include "AblPlayAnimationTaskScratchPad.generated.h"

class UAblAbilityComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblPlayAnimationTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnPlayAnimationPlayed OnAnimationPlayedDelegate;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UAblAbilityComponent>> AbilityComponents;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<USkeletalMeshComponent>> SingleNodeSkeletalComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float EndTimeAdjust;
    
    UAblPlayAnimationTaskScratchPad();
};

