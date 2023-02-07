#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsBlendDomainScalarValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UExposureExpressionsBlendDomainScalarValue : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UExposureExpressionsBlendDomainScalarValue();
};

