#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetInput.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetInput : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetInput();
};

