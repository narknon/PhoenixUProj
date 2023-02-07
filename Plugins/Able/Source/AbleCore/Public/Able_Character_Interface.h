#pragma once
#include "CoreMinimal.h"
#include "EInteractionProject.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "Able_Character_Interface.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityContext;
class UInteractionArchitectAsset;

UINTERFACE(Blueprintable, MinimalAPI)
class UAble_Character_Interface : public UInterface {
    GENERATED_BODY()
};

class IAble_Character_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool PlayAbilityByClass(FName InAbilityChannelName, UClass* InAblAbilitClass, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetAbilityWithMultipleAssetsAndTags(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InArchitectAssets, const TArray<FGameplayTagContainer>& InArchitectTags, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetAbilityWithMultipleAssets(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InArchitectAssets, const FGameplayTagContainer& InArchitectTagContainer, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetAbilityFromInteractionArchitect(const FGameplayTagContainer& InSourceTagContainer, UInteractionArchitectAsset* InArchitectAsset, const FGameplayTagContainer& InArchitectTagContainer, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ExecuteAbilityOnChannelByClass(FName ChannelName, UClass* InAblAbilitClass, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ExecuteAbilityByClass(UClass* InAblAbilitClass, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelAbilityByContext(UAblAbilityContext* InAblAbilityContext);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelAbilityByChannel(FName InAbilityChannelName);
    
};

