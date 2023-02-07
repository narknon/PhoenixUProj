#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRuleOr.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleOr : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULumosScalabilitySettingsRule*> Rules;
    
    ULumosScalabilitySettingsRuleOr();
};

