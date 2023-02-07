#pragma once
#include "CoreMinimal.h"
#include "PostProcessExposureValues.h"
#include "PostProcessExposureValuesUnreal.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FPostProcessExposureValuesUnreal : public FPostProcessExposureValues {
    GENERATED_BODY()
public:
    FPostProcessExposureValuesUnreal();
};

