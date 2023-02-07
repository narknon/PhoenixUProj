#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "BaseArchitectComponent.generated.h"

class UAnimationArchitectTagProvider;
class UBaseArchitectAsset;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATIONARCHITECTRUNTIME_API UBaseArchitectComponent : public UActorComponent, public IAnimationArchitect_TagProviderInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UBaseArchitectAsset>> HardBaseArchitectAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> AnimationTagProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BaseArchitectGamePlayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> RequestedLoadedAssets;
    
public:
    UBaseArchitectComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveGameplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    bool GameplayTagContainerHasTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void AddGameplayTag(const FGameplayTag& InGameplayTag);
    
    
    // Fix for true pure virtual functions not being implemented
};

