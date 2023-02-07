#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesIntegerName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesIntegerName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesIntegerName();
};

