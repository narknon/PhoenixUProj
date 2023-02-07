#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkinFXAutoTriggerDelegateDelegate.h"
#include "SkinFXAutoTriggerDriverTracker.h"
#include "SkinFXAutoTriggerComponent.generated.h"

class AActor;
class UObject;
class USkinFXAutoTriggerDriver;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SKINFX_API USkinFXAutoTriggerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USkinFXAutoTriggerDriver*> Drivers;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggerDelegate DynamicEventDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggerDriverTracker Tracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisabled;
    
public:
    USkinFXAutoTriggerComponent();
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void RemoveDriverByName(FName TriggerName);
    
    UFUNCTION(BlueprintCallable)
    void RemoveDriver(const USkinFXAutoTriggerDriver* Driver);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RefreshAll(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void Refresh(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDriverByName(FName TriggerName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDriver(const USkinFXAutoTriggerDriver* Driver) const;
    
    UFUNCTION(BlueprintCallable)
    void AddDriver(const USkinFXAutoTriggerDriver* Driver);
    
};

