#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "LumosScalabilitySettingsRule.h"
#include "LumosScalabilitySettingsRuleNPCKey.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleNPCKey : public ULumosScalabilitySettingsRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NPCKey;
    
    ULumosScalabilitySettingsRuleNPCKey();
};

