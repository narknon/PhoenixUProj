#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalUpdateSingleParameter.h"
#include "WeatherDecalUpdateSingleParameterFlex.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalUpdateSingleParameterFlex : public UWeatherDecalUpdateSingleParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Types;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    UWeatherDecalUpdateSingleParameterFlex();
};

