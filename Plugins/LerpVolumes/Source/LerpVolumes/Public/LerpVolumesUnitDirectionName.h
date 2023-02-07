#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesUnitDirectionName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesUnitDirectionName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesUnitDirectionName();
};

