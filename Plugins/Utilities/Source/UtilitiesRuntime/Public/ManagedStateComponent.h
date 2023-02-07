#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EManagedVisibilityPriority.h"
#include "ManagedStateComponent.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTILITIESRUNTIME_API UManagedStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UManagedStateComponent();
private:
    UFUNCTION(BlueprintCallable)
    static void BP_TryFinishSettingHiddenUnprioritized(AActor* Actor, UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    static void BP_StartSettingHiddenUnprioritized(AActor* Actor, bool IsHidden, UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    static void BP_StartSettingHiddenPrioritized(AActor* Actor, bool IsHidden, EManagedVisibilityPriority Priority, UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    static void BP_FinishSettingHiddenUnprioritized(AActor* Actor, UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    static void BP_FinishSettingHiddenPrioritized(AActor* Actor, EManagedVisibilityPriority Priority, UObject* Provider);
    
};

