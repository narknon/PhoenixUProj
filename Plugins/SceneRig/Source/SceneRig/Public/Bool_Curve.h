#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Curves/CurveFloat.h"
#include "Bool_Curve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UBool_Curve : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UBool_Curve();
};

