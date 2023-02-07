#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "AnimationProvider.h"
#include "GameplayTagContainer.h"
#include "Animation_FromPoseGroup.generated.h"

class UAnimationArchitectTagProvider;
class UPoseGroupProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimation_FromPoseGroup : public UAnimationProvider, public IAnimationArchitect_TagProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TransitionFromPreviousPose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPoseGroupProvider* TransitionFromPoseGroupOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UAnimation_FromPoseGroup();
    
    // Fix for true pure virtual functions not being implemented
};

