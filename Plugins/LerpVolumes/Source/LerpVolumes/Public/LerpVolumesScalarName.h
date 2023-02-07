#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesScalarName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesScalarName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesScalarName();
};

