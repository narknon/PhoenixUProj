#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalSetup.generated.h"

class UMaterialInterface;
class UWeatherDecalPlacement;

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherDecalSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DecalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DecalName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeatherDecalPlacement* DecalPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DecalSortOrderOffset;
    
    FWeatherDecalSetup();
};

