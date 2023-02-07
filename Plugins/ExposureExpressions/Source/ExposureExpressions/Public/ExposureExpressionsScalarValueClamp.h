#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsScalarValueClamp.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueClamp : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Max;
    
    UExposureExpressionsScalarValueClamp();
};

