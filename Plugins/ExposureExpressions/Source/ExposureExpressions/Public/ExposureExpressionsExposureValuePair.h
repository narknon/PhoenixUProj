#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsExposureValuePair.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValuePair : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* ExposureA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* ExposureB;
    
    UExposureExpressionsExposureValuePair();
};

