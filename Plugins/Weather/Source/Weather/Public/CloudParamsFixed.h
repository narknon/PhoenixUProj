#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsWeatherWindParams.h"
#include "CloudParameters.h"
#include "CloudParams.h"
#include "CloudParamsFixed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class WEATHER_API UCloudParamsFixed : public UCloudParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCloudParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherWindParams WindParams;
    
    UCloudParamsFixed();
};

