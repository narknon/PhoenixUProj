#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesColorName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesColorName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesColorName();
};

