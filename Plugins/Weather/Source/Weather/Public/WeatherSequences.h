#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherDefinitionName.h"
#include "WeatherSequenceInfo.h"
#include "WeatherSequenceInfoWithProbability.h"
#include "WeatherSequenceRedirector.h"
#include "WeatherSequences.generated.h"

class UWeatherCustomSequences;
class UWeatherSequence;

UCLASS(Blueprintable)
class WEATHER_API UWeatherSequences : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfo> GeneralSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfoWithProbability> SummerSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfoWithProbability> FallSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfoWithProbability> WinterSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfoWithProbability> SpringSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfo> MissionSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfo> PrivateSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceInfo> EditorOnlySequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeatherCustomSequences* CustomSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherSequenceRedirector> Redirectors;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWeatherSequence*> HardLoadSequences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName FallDefaultWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName WinterDefaultWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName SpringDefaultWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName SummerDefaultWeather;
    
    UWeatherSequences();
};

