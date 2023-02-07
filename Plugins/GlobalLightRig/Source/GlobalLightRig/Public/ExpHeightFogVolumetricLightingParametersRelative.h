#pragma once
#include "CoreMinimal.h"
#include "AdjustedValueFloat.h"
#include "ExpHeightFogVolumetricLightingParametersRelative.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FExpHeightFogVolumetricLightingParametersRelative {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingDirectionalLightScattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingDirectionalLightDesaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingShadowsNearMinimum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingShadowsFarMinimum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingShadowsNearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingShadowsFarDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingCloudShadowsNearMinimum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingCloudShadowsFarMinimum;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingCloudShadowsNearDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingCloudShadowsFarDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingHistoryWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingHistoryWeightStableCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat VolumetricLightingHistoryWeightMovingLight;
    
    FExpHeightFogVolumetricLightingParametersRelative();
};

