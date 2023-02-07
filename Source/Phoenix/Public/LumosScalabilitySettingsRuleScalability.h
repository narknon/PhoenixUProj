#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityCategory.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRuleScalability.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleScalability : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityCategory Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Levels;
    
    ULumosScalabilitySettingsRuleScalability();
};

