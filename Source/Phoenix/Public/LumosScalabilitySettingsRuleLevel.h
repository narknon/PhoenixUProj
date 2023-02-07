#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRuleLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleLevel : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelNameContains;
    
    ULumosScalabilitySettingsRuleLevel();
};

