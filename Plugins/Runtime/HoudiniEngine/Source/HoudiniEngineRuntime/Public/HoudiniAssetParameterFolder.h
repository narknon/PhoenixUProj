#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterFolder.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterFolder : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterFolder();
};

