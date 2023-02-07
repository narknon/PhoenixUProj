#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Conditional.h"
#include "RPGTriggerEffect_DropLootBag.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_DropLootBag : public URPGTriggerEffect_Conditional {
    GENERATED_BODY()
public:
    URPGTriggerEffect_DropLootBag();
};

