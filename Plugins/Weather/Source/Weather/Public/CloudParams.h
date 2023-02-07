#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CloudParams.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class WEATHER_API UCloudParams : public UObject {
    GENERATED_BODY()
public:
    UCloudParams();
};

