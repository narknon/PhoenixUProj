#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ActorDamaged.h"
#include "RPGTriggerEffect_ModifyCooldownGroupOnDamage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_ModifyCooldownGroupOnDamage : public URPGTriggerEffect_ActorDamaged {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CooldownGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownModification;
    
public:
    URPGTriggerEffect_ModifyCooldownGroupOnDamage();
};

