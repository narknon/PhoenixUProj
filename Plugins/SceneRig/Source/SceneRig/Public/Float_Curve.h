#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "Curves/CurveFloat.h"
#include "Float_Curve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UFloat_Curve : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UFloat_Curve();
};

