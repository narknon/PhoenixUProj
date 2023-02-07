#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_FillFocusMeterOnPlayerEpiskey.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_FillFocusMeterOnPlayerEpiskey : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthThresholdBefore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthToFocusRatio;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
public:
    URPGTriggerEffect_FillFocusMeterOnPlayerEpiskey();
protected:
    UFUNCTION(BlueprintCallable)
    void OnEpiskeyHealing(AActor* Instigator, float InHealthChange, AActor* TargetActor);
    
};

