#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ProtegoReflectAttack.h"
#include "RPGTriggerEffect_ManageTacticianTokens.generated.h"

class URPGAbilityBase;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_ManageTacticianTokens : public URPGTriggerEffect_ProtegoReflectAttack {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxTokens;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URPGAbilityBase* Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbilityDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AbilityOnPlayer;
    
public:
    URPGTriggerEffect_ManageTacticianTokens();
};

