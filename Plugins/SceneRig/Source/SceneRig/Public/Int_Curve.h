#pragma once
#include "CoreMinimal.h"
#include "IntProvider.h"
#include "Curves/CurveFloat.h"
#include "Int_Curve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UInt_Curve : public UIntProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UInt_Curve();
};

