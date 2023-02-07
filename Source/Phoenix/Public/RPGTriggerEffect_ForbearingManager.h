#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_RecoverFromDamage.h"
#include "RPGTriggerEffect_ForbearingManager.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_ForbearingManager : public URPGTriggerEffect_RecoverFromDamage {
    GENERATED_BODY()
public:
    URPGTriggerEffect_ForbearingManager();
};

