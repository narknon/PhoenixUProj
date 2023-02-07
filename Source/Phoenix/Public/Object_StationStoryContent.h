#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "ObjectProvider.h"
#include "GameplayTagContainer.h"
#include "Object_StationStoryContent.generated.h"

class UAnimationArchitectTagProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UObject_StationStoryContent : public UObjectProvider, public IAnimationArchitect_TagProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    UObject_StationStoryContent();
    
    // Fix for true pure virtual functions not being implemented
};

