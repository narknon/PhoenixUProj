#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ExpHeightFogParameters.h"
#include "FogDefinitions.generated.h"

class UFogParams;
class UMaterialParameterCollection;
class UNiagaraParameterCollection;

UCLASS(Blueprintable)
class WEATHER_API UFogDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFogParams*> Definitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogParameters BaseFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* SurfaceFogMaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* SurfaceFogNiagaraParameterCollection;
    
    UFogDefinitions();
};

