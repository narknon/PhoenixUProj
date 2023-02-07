#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "SkeletalMeshDriver.h"
#include "GameplayTagContainer.h"
#include "DialogueLineRule.h"
#include "DialogueLineRule_BodyIdle.generated.h"

class UBaseArchitectAsset;
class UPoseGroupProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_BodyIdle : public UDialogueLineRule, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPoseGroupProvider* DefaultPoseGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBaseArchitectAsset* PoseGroupLookup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PoseGroupTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference IdleLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference TransitionLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutTime;
    
    UDialogueLineRule_BodyIdle();
    
    // Fix for true pure virtual functions not being implemented
};

