#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "PoseGroupProvider.h"
#include "GameplayTagContainer.h"
#include "PoseGroup_TagLookupOnAssets.generated.h"

class UAnimationArchitectTagProvider;
class UBaseArchitectFilter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UPoseGroup_TagLookupOnAssets : public UPoseGroupProvider, public IAnimationArchitect_TagProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBaseArchitectFilter* Filter;
    
    UPoseGroup_TagLookupOnAssets();
    
    // Fix for true pure virtual functions not being implemented
};

