#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CloudsPresetParams.h"
#include "CloudsPresetParamsFromPreset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudsPresetParamsFromPreset : public UCloudsPresetParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Preset;
    
    UCloudsPresetParamsFromPreset();
};

