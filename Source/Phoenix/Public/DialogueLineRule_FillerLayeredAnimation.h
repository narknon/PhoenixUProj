#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "SkeletalMeshDriver.h"
#include "GameplayTagContainer.h"
#include "DialogueLineRule.h"
#include "ELineRule_LayeredAnimationType.h"
#include "DialogueLineRule_FillerLayeredAnimation.generated.h"

class UAnimMaskAsset;
class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_FillerLayeredAnimation : public UDialogueLineRule, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMaskAsset* Mask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELineRule_LayeredAnimationType ActiveWhen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeightVariability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* ComputedBlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendTimeVariability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PaddingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PaddingTimeVariability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FitSmallAnimations;
    
    UDialogueLineRule_FillerLayeredAnimation();
    
    // Fix for true pure virtual functions not being implemented
};

