#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterMultiparm.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterMultiparm : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterMultiparm();
};

