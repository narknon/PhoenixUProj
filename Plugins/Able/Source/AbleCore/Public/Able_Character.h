#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_Character.h"
#include "EInteractionProject.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "Able_Character_Interface.h"
#include "Templates/SubclassOf.h"
#include "Able_Character.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityComponent;
class UAblAbilityContext;
class UAblPhysicalBodyManager;
class UInteractionArchitectAsset;
class URagdollControlComponent;

UCLASS(Blueprintable)
class ABLECORE_API AAble_Character : public AAnimationArchitect_Character, public IAble_Character_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayHierarchyTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AblAbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URagdollControlComponent* RagdollControlComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblPhysicalBodyManager* PhysicalBodyManager;
    
    AAble_Character(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PlayAbilityByClass(FName InAbilityChannelName, UClass* InAblAbilitClass, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetAbilityWithMultipleAssetsAndTags(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InArchitectAssets, const TArray<FGameplayTagContainer>& InArchitectTags, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetAbilityWithMultipleAssets(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InArchitectAssets, const FGameplayTagContainer& InArchitectTagContainer, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetAbilityFromInteractionArchitect(const FGameplayTagContainer& InSourceTagContainer, UInteractionArchitectAsset* InArchitectAsset, const FGameplayTagContainer& InArchitectTagContainer, EInteractionProject Project, bool& bOutIsAdditive, TSubclassOf<UAblAbility>& OutAbilityClass);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ExecuteAbilityOnChannelByClass(FName ChannelName, UClass* InAblAbilitClass, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ExecuteAbilityByClass(UClass* InAblAbilitClass, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CancelAbilityByContext(UAblAbilityContext* InAblAbilityContext);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CancelAbilityByChannel(FName InAbilityChannelName);
    
    
    // Fix for true pure virtual functions not being implemented
};

