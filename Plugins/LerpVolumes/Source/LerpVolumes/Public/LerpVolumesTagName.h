#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesName.h"
#include "LerpVolumesTagName.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesTagName : public FLerpVolumesName {
    GENERATED_BODY()
public:
    LERPVOLUMES_API FLerpVolumesTagName();
};

