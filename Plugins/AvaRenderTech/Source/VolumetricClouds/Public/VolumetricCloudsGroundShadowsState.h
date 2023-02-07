#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsGroundShadowsState.generated.h"

class ULightComponent;
class UMaterialInstanceDynamic;
class UTexture;
class UTexture2DAlias;

USTRUCT(BlueprintType)
struct FVolumetricCloudsGroundShadowsState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULightComponent> LightComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* LightFunctionMID;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture2DAlias> WeatherMap;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture> RoilTexture;
    
    VOLUMETRICCLOUDS_API FVolumetricCloudsGroundShadowsState();
};

