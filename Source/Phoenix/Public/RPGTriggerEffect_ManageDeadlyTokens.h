#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_RecoverFromDamage.h"
#include "RPGTriggerEffect_ManageDeadlyTokens.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_ManageDeadlyTokens : public URPGTriggerEffect_RecoverFromDamage {
    GENERATED_BODY()
public:
    URPGTriggerEffect_ManageDeadlyTokens();
};

