#pragma once
#include "CoreMinimal.h"
#include "PostProcessExposureValues.h"
#include "PostProcessExposureValuesUnitless.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FPostProcessExposureValuesUnitless : public FPostProcessExposureValues {
    GENERATED_BODY()
public:
    FPostProcessExposureValuesUnitless();
};

