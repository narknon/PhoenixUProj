#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRulePlatforms.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRulePlatforms : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Platforms;
    
    ULumosScalabilitySettingsRulePlatforms();
};

