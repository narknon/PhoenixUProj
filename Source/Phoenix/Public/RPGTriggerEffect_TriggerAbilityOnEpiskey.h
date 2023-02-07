#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_OnEpiskey.h"
#include "RPGTriggerEffect_TriggerAbilityOnEpiskey.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_TriggerAbilityOnEpiskey : public URPGTriggerEffect_OnEpiskey {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbilityBaseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbilityTimePerHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbilityTimeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AbilityOnPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGAbilityBase* Ability;
    
public:
    URPGTriggerEffect_TriggerAbilityOnEpiskey();
};

