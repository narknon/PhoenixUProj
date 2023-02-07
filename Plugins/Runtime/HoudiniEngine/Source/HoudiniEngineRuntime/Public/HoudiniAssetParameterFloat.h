#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterFloat.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterFloat : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterFloat();
};

