#pragma once
#include "CoreMinimal.h"
#include "WeatherDefinitionName.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_Weather.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_Weather : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherDefinitionName> WeatherToCheck;
    
    UWorldEventCondition_Weather();
};

