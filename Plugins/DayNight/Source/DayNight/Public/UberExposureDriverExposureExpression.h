#pragma once
#include "CoreMinimal.h"
#include "UberExposureDriver.h"
#include "UberExposureDriverExposureExpression.generated.h"

class UExposureExpressionsExposureValue;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UUberExposureDriverExposureExpression : public UUberExposureDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* Expression;
    
    UUberExposureDriverExposureExpression();
};

