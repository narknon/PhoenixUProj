#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterFile.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterFile : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterFile();
};

