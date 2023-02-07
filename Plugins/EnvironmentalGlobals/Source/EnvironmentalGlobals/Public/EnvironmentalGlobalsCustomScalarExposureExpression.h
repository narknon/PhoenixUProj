#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarModsBase.h"
#include "EnvironmentalGlobalsCustomScalarExposureExpression.generated.h"

class UExposureExpressionsScalarValue;

UCLASS(Blueprintable, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalarExposureExpression : public UEnvironmentalGlobalsCustomScalarModsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Expression;
    
    UEnvironmentalGlobalsCustomScalarExposureExpression();
};

