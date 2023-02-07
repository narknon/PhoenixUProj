#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TriggerEffectManager.generated.h"

class UTriggerEffect;

UCLASS(Blueprintable)
class TOOLSET_API UTriggerEffectManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffect* InactiveTriggerEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTriggerEffect*> TriggerEffectStack;
    
public:
    UTriggerEffectManager();
    UFUNCTION(BlueprintCallable)
    void ResumeTriggerEffects();
    
    UFUNCTION(BlueprintCallable)
    void PauseTriggerEffects();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateTriggerEffect(UTriggerEffect* TriggerEffect, int32 ControllerId);
    
    UFUNCTION(BlueprintCallable)
    void ActivateTriggerEffect(UTriggerEffect* TriggerEffect, int32 ControllerId);
    
};

