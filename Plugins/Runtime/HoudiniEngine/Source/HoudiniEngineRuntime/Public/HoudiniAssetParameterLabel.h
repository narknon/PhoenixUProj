#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterLabel.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterLabel : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterLabel();
};

