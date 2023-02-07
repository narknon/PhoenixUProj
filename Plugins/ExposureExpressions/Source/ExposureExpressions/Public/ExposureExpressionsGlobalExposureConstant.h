#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureConstantName.h"
#include "ExposureExpressionsGlobalExposureValueBase.h"
#include "ExposureExpressionsGlobalExposureConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsGlobalExposureConstant : public UExposureExpressionsGlobalExposureValueBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExposureConstantName GlobalConstant;
    
    UExposureExpressionsGlobalExposureConstant();
};

