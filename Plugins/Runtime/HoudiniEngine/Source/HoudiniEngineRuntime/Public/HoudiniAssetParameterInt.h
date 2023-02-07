#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterInt.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterInt : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterInt();
};

