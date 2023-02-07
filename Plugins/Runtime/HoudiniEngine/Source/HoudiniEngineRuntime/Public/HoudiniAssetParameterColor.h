#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterColor.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterColor : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterColor();
};

