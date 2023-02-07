#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "GameplayTagContainer.h"
#include "AnimationSetProvider.h"
#include "AnimationSet_TagLookup.generated.h"

class UActorProvider;
class UAnimationArchitectTagProvider;
class UBaseArchitectFilter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationSet_TagLookup : public UAnimationSetProvider, public IAnimationArchitect_TagProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* LookupOnActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBaseArchitectFilter* Filter;
    
    UAnimationSet_TagLookup();
    
    // Fix for true pure virtual functions not being implemented
};

