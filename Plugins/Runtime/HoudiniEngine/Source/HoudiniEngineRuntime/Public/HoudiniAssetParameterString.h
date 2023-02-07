#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterString.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterString : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterString();
};

