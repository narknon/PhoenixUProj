#pragma once
#include "CoreMinimal.h"
#include "WeatherVolumeSortable.h"
#include "WeatherVolumeSortablePreload.generated.h"

class UObject;

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherVolumeSortablePreload : public AWeatherVolumeSortable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> PreloadedObjects;
    
public:
    AWeatherVolumeSortablePreload(const FObjectInitializer& ObjectInitializer);
};

