#pragma once
#include "CoreMinimal.h"
#include "EnvQueryInstanceBlueprintWrapperEx.h"
#include "StationQueryData.h"
#include "EnvQueryInstance_Station.generated.h"

UCLASS(Blueprintable)
class UEnvQueryInstance_Station : public UEnvQueryInstanceBlueprintWrapperEx {
    GENERATED_BODY()
public:
    UEnvQueryInstance_Station();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FStationQueryData> GetResultsAsStationQueryData();
    
};

