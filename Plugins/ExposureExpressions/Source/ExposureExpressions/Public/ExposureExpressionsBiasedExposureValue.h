#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueSingle.h"
#include "ExposureExpressionsBiasedExposureValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsBiasedExposureValue : public UExposureExpressionsExposureValueSingle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoExposureBiasBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoExposureBiasVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoExposureBiasCurve;
    
    UExposureExpressionsBiasedExposureValue();
};

