#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesLevelName.h"
#include "LumosScalabilitySettingsRuleLevelBase.h"
#include "LumosScalabilitySettingsRuleLevelsExact.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilitySettingsRuleLevelsExact : public ULumosScalabilitySettingsRuleLevelBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesLevelName> Levels;
    
    ULumosScalabilitySettingsRuleLevelsExact();
};

