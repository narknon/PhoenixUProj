#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarMod.h"
#include "EnvironmentalGlobalsCustomScalarModCurve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarModCurve : public UEnvironmentalGlobalsCustomScalarMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* Curve;
    
    UEnvironmentalGlobalsCustomScalarModCurve();
};

