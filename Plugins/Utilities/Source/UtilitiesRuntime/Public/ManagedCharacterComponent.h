#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "EFacialEmotion.h"
#include "EManagedFacialEmotionPriority.h"
#include "EManagedMovementModePriority.h"
#include "ManagedStateComponent.h"
#include "ManagedCharacterComponent.generated.h"

class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTILITIESRUNTIME_API UManagedCharacterComponent : public UManagedStateComponent {
    GENERATED_BODY()
public:
    UManagedCharacterComponent();
    UFUNCTION(BlueprintCallable)
    void StartSettingMovementMode(EMovementMode InMovementMode, EManagedMovementModePriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void SetStartFacialEmotionWithTags(EFacialEmotion Emotion, UObject* Provider, float Transition, EManagedFacialEmotionPriority ManagedFacialEmotionPriority, FGameplayTagContainer AnimTags);
    
    UFUNCTION(BlueprintCallable)
    void SetStartFacialEmotion(EFacialEmotion Emotion, UObject* Provider, float Transition, EManagedFacialEmotionPriority ManagedFacialEmotionPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetFinishFacialEmotion(UObject* Provider, EManagedFacialEmotionPriority ManagedFacialEmotionPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetDefaultFacialEmotion(EFacialEmotion Emotion, float Transition);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingMovementMode(EManagedMovementModePriority Priority, const UObject* Provider);
    
};

