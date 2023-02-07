#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsGlobalScalarValueBase.h"
#include "ExposureExpressionsScalarConstantName.h"
#include "ExposureExpressionsGlobalScalarConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsGlobalScalarConstant : public UExposureExpressionsGlobalScalarValueBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsScalarConstantName GlobalConstant;
    
    UExposureExpressionsGlobalScalarConstant();
};

