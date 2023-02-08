#pragma once
#include "CoreMinimal.h"
#include "AlphaBlend.h"
#include "AblAbilityTaskScratchPad.h"
#include "OnAnimationPlayedDelegate.h"
#include "AblPlayAnimationArchitectTaskScratchPad.generated.h"

class AActor;


UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblPlayAnimationArchitectTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnAnimationPlayed OnAnimationPlayedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimationAsset* AnimationAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAnimationAsset*> BlendTrackAnimationAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AssetEndTimeAdjust;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendOut;
    
    UAblPlayAnimationArchitectTaskScratchPad();
};

