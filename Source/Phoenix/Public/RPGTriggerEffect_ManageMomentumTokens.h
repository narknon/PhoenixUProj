#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_AffectedBySpell.h"
#include "RPGTriggerEffect_ManageMomentumTokens.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ManageMomentumTokens : public URPGTriggerEffect_AffectedBySpell {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGAbilityBase* Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbilityDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AbilityOnPlayer;
    
public:
    URPGTriggerEffect_ManageMomentumTokens();
};

