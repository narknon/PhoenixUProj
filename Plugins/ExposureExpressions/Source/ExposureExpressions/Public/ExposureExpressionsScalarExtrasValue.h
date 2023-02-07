#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraScalarName.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsScalarExtrasValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarExtrasValue : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraScalarName Value;
    
    UExposureExpressionsScalarExtrasValue();
};

