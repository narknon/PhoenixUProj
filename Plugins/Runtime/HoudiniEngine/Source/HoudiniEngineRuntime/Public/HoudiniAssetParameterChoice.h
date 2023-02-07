#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterChoice.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterChoice : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterChoice();
};

