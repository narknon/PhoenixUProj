#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VolumetricCloudsSkyLightParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsSkyLightParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloudOutput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloudAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Desaturate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor GroundColor;
    
    FVolumetricCloudsSkyLightParameters();
};

