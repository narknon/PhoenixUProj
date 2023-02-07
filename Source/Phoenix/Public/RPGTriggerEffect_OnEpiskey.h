#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_OnEpiskey.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_OnEpiskey : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthThresholdBefore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthThresholdAfter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
public:
    URPGTriggerEffect_OnEpiskey();
protected:
    UFUNCTION(BlueprintCallable)
    void OnHealing(const UObject* i_caller, float InHealthChange);
    
};

