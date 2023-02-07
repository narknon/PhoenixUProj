#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRuleNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleNot : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULumosScalabilitySettingsRule* Rule;
    
    ULumosScalabilitySettingsRuleNot();
};

