#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "AnimationArchitectTagsChangedDelegate.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "ArchitectType.h"
#include "EInteractionProject.h"
#include "InteractionArchitectTagsChangedDelegate.h"
#include "ObjectArchitectTagsChangedDelegate.h"
#include "PreLoadAssetInterface.h"
#include "StationArchitectTagsChangedDelegate.h"
#include "AnimationArchitectComponent.generated.h"

class UAnimationArchitectAsset;
class UAnimationArchitectTagProvider;
class UInteractionArchitectAsset;
class UObjectArchitectAsset;
class UStationArchitectAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATIONARCHITECTRUNTIME_API UAnimationArchitectComponent : public UActorComponent, public IAnimationArchitect_TagProviderInterface, public IPreLoadAssetInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ArchitectType> AssetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectAsset*> HardAnimationArchitectAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimationArchitectAsset* TempAnimationArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStationArchitectAsset*> HardStationArchitectAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStationArchitectAsset*> HardStationArchitectSceneRigAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObjectArchitectAsset*> HardObjectArchitectAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EInteractionProject, UInteractionArchitectAsset*> HardInteractionAssetMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationArchitectGameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationArchitectPersistentGamePlayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> AnimationTagProviders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer InteractionArchitectGameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer InteractionArchitectPersistentGamePlayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer StationArchitectGamePlayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer StationArchitectSceneRigTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ObjectArchitectGamePlayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationArchitectAssetTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer InteractionReactionAssetTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectAsset*> DynamicAnimationArchitectAssets;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimationArchitectTagsChanged AnimationArchitectTagsChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInteractionArchitectTagsChanged InteractionArchitectTagsChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStationArchitectTagsChanged StationArchitectTagsChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FObjectArchitectTagsChanged ObjectArchitectTagsChangedDelegate;
    
    UAnimationArchitectComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveObjectArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveInteractionArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAnimationArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    bool InteractionArchitectTagContainerHasTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    bool InteractionArchitectTagContainerHasAny(const FGameplayTagContainer& InGameplayTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void AddObjectArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void AddInteractionArchitectPersistentGameplayTags(const FGameplayTagContainer& InGameplayTags);
    
    UFUNCTION(BlueprintCallable)
    void AddInteractionArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable)
    void AddAnimationArchitectPersistentGameplayTags(const FGameplayTagContainer& InGameplayTags);
    
    UFUNCTION(BlueprintCallable)
    void AddAnimationArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    
    // Fix for true pure virtual functions not being implemented
};

