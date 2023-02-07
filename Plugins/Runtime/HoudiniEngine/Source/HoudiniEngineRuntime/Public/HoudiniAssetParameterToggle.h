#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterToggle.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterToggle : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterToggle();
};

