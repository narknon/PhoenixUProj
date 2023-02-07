#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsColorCurveVarMode.h"
#include "EEnvironmentalGlobalsColorVarConversion.h"
#include "EEnvironmentalGlobalsValue.h"
#include "EnvironmentalGlobalsColorVar.h"
#include "EnvironmentalGlobalsColorCurveVar.generated.h"

class UCurveLinearColor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsColorCurveVar : public UEnvironmentalGlobalsColorVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveLinearColor* Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsValue CurveX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsColorVarConversion Conversion;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnvironmentalGlobalsColorCurveVarMode Mode;
    
    UEnvironmentalGlobalsColorCurveVar();
};

