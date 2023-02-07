#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_OnHitBySpell.h"
#include "RPGTriggerEffect_CauseDisturbanceOnSpellImpact.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_CauseDisturbanceOnSpellImpact : public URPGTriggerEffect_OnHitBySpell {
    GENERATED_BODY()
public:
    URPGTriggerEffect_CauseDisturbanceOnSpellImpact();
};

