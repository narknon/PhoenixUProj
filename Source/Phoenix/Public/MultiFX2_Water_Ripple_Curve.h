#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "ENiagraWaterRippleCurveProperty.h"
#include "MultiFX2_Water_Ripple_Curve.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_Water_Ripple_Curve : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENiagraWaterRippleCurveProperty SourceProperty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveDuration;
    
public:
    UMultiFX2_Water_Ripple_Curve();
};

