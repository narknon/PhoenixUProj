#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterButton.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterButton : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterButton();
};

