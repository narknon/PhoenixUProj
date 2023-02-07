#pragma once
#include "CoreMinimal.h"
#include "PostProcessExposureValues.h"
#include "PostProcessExposureValuesEV100.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FPostProcessExposureValuesEV100 : public FPostProcessExposureValues {
    GENERATED_BODY()
public:
    FPostProcessExposureValuesEV100();
};

