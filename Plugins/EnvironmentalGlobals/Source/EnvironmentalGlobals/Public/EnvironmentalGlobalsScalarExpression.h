#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsScalarConversion.h"
#include "EnvironmentalGlobalsScalarVar.h"
#include "EnvironmentalGlobalsScalarExpression.generated.h"

class UExposureExpressionsExposureValue;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsScalarExpression : public UEnvironmentalGlobalsScalarVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* Expression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsScalarConversion Conversion;
    
    UEnvironmentalGlobalsScalarExpression();
};

