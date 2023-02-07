#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilityOverrideBase.h"
#include "LumosScalabilityOverrideWithRule.generated.h"

class ULumosScalabilitySettingsRule;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityOverrideWithRule : public ULumosScalabilityOverrideBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULumosScalabilitySettingsRule* Rule;
    
    ULumosScalabilityOverrideWithRule();
};

