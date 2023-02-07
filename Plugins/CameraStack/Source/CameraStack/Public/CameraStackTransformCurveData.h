#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraStackTransformCurveData.generated.h"

class UCurveFloat;
class UCurveVector;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackTransformCurveData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* CameraLocationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* FocalPointCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* InversePitchCurve;
    
    UCameraStackTransformCurveData();
};

