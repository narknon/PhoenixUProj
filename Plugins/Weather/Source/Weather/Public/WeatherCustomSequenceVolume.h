#pragma once
#include "CoreMinimal.h"
#include "WeatherCustomSequenceName.h"
#include "WeatherVolumeSortablePreload.h"
#include "WeatherCustomSequenceVolume.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherCustomSequenceVolume : public AWeatherVolumeSortablePreload {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherCustomSequenceName CustomSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseInFall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseInWinter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseInSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseInSummer;
    
    AWeatherCustomSequenceVolume(const FObjectInitializer& ObjectInitializer);
};

