#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsExposureValueSelect.generated.h"

class UExposureExpressionsScalarValue;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueSelect : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Constant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* ExposureTrue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* ExposureFalse;
    
    UExposureExpressionsExposureValueSelect();
};

