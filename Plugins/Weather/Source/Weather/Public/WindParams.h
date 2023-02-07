#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WindParams.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class WEATHER_API UWindParams : public UObject {
    GENERATED_BODY()
public:
    UWindParams();
};

