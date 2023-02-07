#pragma once
#include "CoreMinimal.h"
#include "CloudsPresetParams.h"
#include "VolumetricCloudsPresetParameters.h"
#include "CloudsPresetParamsRaw.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudsPresetParamsRaw : public UCloudsPresetParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsPresetParameters Parameters;
    
    UCloudsPresetParamsRaw();
};

