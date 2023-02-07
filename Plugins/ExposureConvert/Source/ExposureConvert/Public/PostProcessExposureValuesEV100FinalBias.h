#pragma once
#include "CoreMinimal.h"
#include "PostProcessExposureValuesEV100.h"
#include "PostProcessExposureValuesEV100FinalBias.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FPostProcessExposureValuesEV100FinalBias : public FPostProcessExposureValuesEV100 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoExposureCurveBias;
    
    FPostProcessExposureValuesEV100FinalBias();
};

