#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameterMultiparm.h"
#include "HoudiniAssetParameterRamp.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterRamp : public UHoudiniAssetParameterMultiparm {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterRamp();
};

