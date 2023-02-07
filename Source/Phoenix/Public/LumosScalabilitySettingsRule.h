#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LumosScalabilitySettingsRule.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ULumosScalabilitySettingsRule : public UObject {
    GENERATED_BODY()
public:
    ULumosScalabilitySettingsRule();
};

