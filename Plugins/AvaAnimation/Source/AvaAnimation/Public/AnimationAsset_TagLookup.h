#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimationProvider.h"
#include "AnimationAsset_TagLookup.generated.h"

class UActorProvider;
class UAnimationArchitectTagProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationAsset_TagLookup : public UAnimationProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* LookupOnActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UAnimationAsset_TagLookup();
};

