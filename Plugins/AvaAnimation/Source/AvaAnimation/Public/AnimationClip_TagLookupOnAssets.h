#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "GameplayTagContainer.h"
#include "AnimationClipProvider.h"
#include "AnimationClip_TagLookupOnAssets.generated.h"

class UAnimationArchitectTagProvider;
class UBaseArchitectFilter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationClip_TagLookupOnAssets : public UAnimationClipProvider, public IAnimationArchitect_TagProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBaseArchitectFilter* Filter;
    
    UAnimationClip_TagLookupOnAssets();
    
    // Fix for true pure virtual functions not being implemented
};

