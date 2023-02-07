#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereSkyOnlyColorParameter.h"
#include "SkyAtmosphereSkyOnlyParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyAtmosphereSkyOnlyParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverallBrightness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverallSaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyColorParameter SkyMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyColorParameter SunDiskMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyColorParameter MoonDiskMod;
    
    FSkyAtmosphereSkyOnlyParameters();
};

