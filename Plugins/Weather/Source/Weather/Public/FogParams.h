#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FogParams.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class WEATHER_API UFogParams : public UObject {
    GENERATED_BODY()
public:
    UFogParams();
};

