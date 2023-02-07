#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "AnimationArchitect_ActorInterface.generated.h"

class UAnimationArchitectAsset;
class UAnimationArchitectComponent;
class UObject;

UINTERFACE(Blueprintable, MinimalAPI)
class UAnimationArchitect_ActorInterface : public UInterface {
    GENERATED_BODY()
};

class IAnimationArchitect_ActorInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UAnimationArchitectComponent* GetAnimationArchitectComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FindSceneRigAsset(const FGameplayTagContainer& InAnimTagContainer, UObject*& OutSceneRig);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool FindArchitectAssets(const FGameplayTagContainer& InTagContainer, TArray<UObject*>& Assets);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FindArchitectAssetFromMonolythicAsset(const FGameplayTagContainer& InAssetTypeTagContainer, const FGameplayTagContainer& InTagContainer, UObject*& OutAsset, bool bForceFirstOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FindArchitectAsset(const FGameplayTagContainer& InAnimTagContainer, UObject*& OutAsset, bool bForceFirstOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddAnimationArchitectGamplayTag(const FGameplayTag& InGameplayTag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddAnimationArchitectAsset(UAnimationArchitectAsset* InArchitectAsset);
    
};

