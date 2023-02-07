#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueConstantBase.h"
#include "ExposureExpressionsScalarValueConstantRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueConstantRange : public UExposureExpressionsScalarValueConstantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UExposureExpressionsScalarValueConstantRange();
};

