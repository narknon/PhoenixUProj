#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesLevelName.h"
#include "LumosScalabilitySettingsRuleLevelBase.h"
#include "LumosScalabilitySettingsRuleLevelExact.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleLevelExact : public ULumosScalabilitySettingsRuleLevelBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLevelName Level;
    
    ULumosScalabilitySettingsRuleLevelExact();
};

