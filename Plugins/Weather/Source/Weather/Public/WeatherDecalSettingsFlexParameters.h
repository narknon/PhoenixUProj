#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalSettingsParameters.h"
#include "WeatherDecalSettingsFlexParameters.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalSettingsFlexParameters : public UWeatherDecalSettingsParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Types;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    UWeatherDecalSettingsFlexParameters();
};

