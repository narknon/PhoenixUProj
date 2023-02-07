#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeatherTimeSyncTime.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherTimeSyncTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan GameSyncBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan SequenceSyncBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan SyncError;
    
    FWeatherTimeSyncTime();
};

