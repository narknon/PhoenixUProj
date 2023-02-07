#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "HoudiniAssetParameterRampCurveFloat.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterRampCurveFloat : public UCurveFloat {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterRampCurveFloat();
};

