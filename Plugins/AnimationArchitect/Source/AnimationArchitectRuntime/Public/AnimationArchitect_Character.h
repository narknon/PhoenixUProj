#pragma once
#include "CoreMinimal.h"
#include "CustomizableCharacterInterface.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "AnimationArchitect_ActorInterface.h"
#include "AnimationArchitect_Character.generated.h"

class UAnimationArchitectComponent;
class UObject;

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API AAnimationArchitect_Character : public ACharacter, public IAnimationArchitect_ActorInterface, public ICustomizableCharacterInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationArchitectComponent* AnimationArchitectComponent;
    
public:
    AAnimationArchitect_Character();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    UAnimationArchitectComponent* GetAnimationArchitectComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool FindArchitectAssets(const FGameplayTagContainer& InAnimTagContainer, TArray<UObject*>& Assets);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FindArchitectAssetFromMonolythicAsset(const FGameplayTagContainer& InAssetTypeTagContainer, const FGameplayTagContainer& InTagContainer, UObject*& OutAsset, bool bForceFirstOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FindArchitectAsset(const FGameplayTagContainer& InAnimTagContainer, UObject*& OutAsset, bool bForceFirstOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddInteractionArchitectGameplayTag(const FGameplayTag& InGamepayTag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddAnimationArchitectGameplayTag(const FGameplayTag& InGameplayTag);
    
    
    // Fix for true pure virtual functions not being implemented
};

