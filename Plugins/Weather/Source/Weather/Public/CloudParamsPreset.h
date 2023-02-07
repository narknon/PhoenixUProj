#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "VolumetricCloudsWeatherWindParams.h"
#include "CloudParams.h"
#include "SunDiskOverrides.h"
#include "CloudParamsPreset.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class WEATHER_API UCloudParamsPreset : public UCloudParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherWindParams WindParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSunDiskOverrides SunDiskOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Overcast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuperExpensiveCloudsCinematicOnly;
    
    UCloudParamsPreset();
};

