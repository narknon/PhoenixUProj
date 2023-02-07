#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnPlayerEpiskeyHealing.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnPlayerEpiskeyHealing : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthThresholdBefore;
    
public:
    URPGAbilityEventListener_OnPlayerEpiskeyHealing();
protected:
    UFUNCTION(BlueprintCallable)
    void OnEpiskeyHealing(AActor* Instigator, float InHealthChange, AActor* TargetActor);
    
};

