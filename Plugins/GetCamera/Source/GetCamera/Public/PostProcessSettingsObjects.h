#pragma once
#include "CoreMinimal.h"
#include "PostProcessSettingsObjects.generated.h"

class UCurveFloat;
class UTexture;
class UTexture2D;
class UTextureCube;

USTRUCT(BlueprintType)
struct FPostProcessSettingsObjects {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture2D> BloomConvolutionTexture;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture> BloomDirtMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTextureCube> AmbientCubemap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCurveFloat> AutoExposureBiasCurve;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture> AutoExposureMeterMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture> LensFlareBokehShape;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTexture> ColorGradingLUT;
    
    GETCAMERA_API FPostProcessSettingsObjects();
};

