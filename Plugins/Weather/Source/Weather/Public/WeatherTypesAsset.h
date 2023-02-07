#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherTypesAsset.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;

UCLASS(Blueprintable)
class WEATHER_API UWeatherTypesAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    UWeatherTypesAsset();
};

