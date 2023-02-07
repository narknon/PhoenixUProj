#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "HoudiniAssetParameterRampCurveColor.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterRampCurveColor : public UCurveLinearColor {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterRampCurveColor();
};

