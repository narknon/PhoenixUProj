#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "VolumetricCloudsLightingParams.h"
#include "VolumetricCloudsWeatherWindParams.h"
#include "VolumetricCloudsActor.generated.h"

class UVolumetricCloudsComponent;

UCLASS(Blueprintable)
class VOLUMETRICCLOUDS_API AVolumetricCloudsActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVolumetricCloudsComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsLightingParams Lighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherWindParams WeatherWind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float GroundShadowsStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bUsePresetLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bUsePresetWeatherWind;
    
    AVolumetricCloudsActor();
};

