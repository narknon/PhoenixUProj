#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WindDefinitions.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;
class UWindParams;

UCLASS(Blueprintable)
class WEATHER_API UWindDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWindParams*> Definitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalizedWindSpeedMetersPerSecond;
    
    UWindDefinitions();
};

