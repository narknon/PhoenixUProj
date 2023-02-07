#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRuleLevelBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleLevelBase : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    ULumosScalabilitySettingsRuleLevelBase();
};

