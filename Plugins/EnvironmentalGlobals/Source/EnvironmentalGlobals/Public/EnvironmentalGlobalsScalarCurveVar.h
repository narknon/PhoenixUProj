#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsScalarConversion.h"
#include "EEnvironmentalGlobalsValue.h"
#include "EnvironmentalGlobalsScalarClamp.h"
#include "EnvironmentalGlobalsScalarVar.h"
#include "EnvironmentalGlobalsScalarCurveVar.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsScalarCurveVar : public UEnvironmentalGlobalsScalarVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsValue CurveX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsScalarConversion Conversion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvironmentalGlobalsScalarClamp ClampMinMax;
    
    UEnvironmentalGlobalsScalarCurveVar();
};

