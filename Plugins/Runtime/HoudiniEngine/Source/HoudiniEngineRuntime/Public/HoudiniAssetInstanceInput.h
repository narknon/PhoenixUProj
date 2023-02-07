#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetInstanceInput.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetInstanceInput : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetInstanceInput();
};

