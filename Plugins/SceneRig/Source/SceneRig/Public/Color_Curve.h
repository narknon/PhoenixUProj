#pragma once
#include "CoreMinimal.h"
#include "ColorProvider.h"
#include "Curves/CurveLinearColor.h"
#include "Color_Curve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UColor_Curve : public UColorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Curve;
    
    UColor_Curve();
};

