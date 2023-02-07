#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilityModifyBase.h"
#include "LumosScalabilityModifyWithRule.generated.h"

class ULumosScalabilitySettingsRule;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityModifyWithRule : public ULumosScalabilityModifyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULumosScalabilitySettingsRule* Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LightingScenarios;
    
    ULumosScalabilityModifyWithRule();
};

