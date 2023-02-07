#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsPresetParams.h"
#include "VolumetricCloudsPresetParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsPresetParameters : public FVolumetricCloudsPresetParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    FVolumetricCloudsPresetParameters();
};

