#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_ActorDamaged.h"
#include "RPGTriggerEffect_FocusGainOnCompanionDamage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_FocusGainOnCompanionDamage : public URPGTriggerEffect_ActorDamaged {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusGain;
    
public:
    URPGTriggerEffect_FocusGainOnCompanionDamage();
};

