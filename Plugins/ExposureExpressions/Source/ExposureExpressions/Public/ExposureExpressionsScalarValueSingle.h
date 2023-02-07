#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsScalarValueSingle.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueSingle : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Value;
    
    UExposureExpressionsScalarValueSingle();
};

