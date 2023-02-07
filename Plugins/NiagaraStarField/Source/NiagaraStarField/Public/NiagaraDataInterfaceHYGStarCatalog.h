#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "PixelStarRenderingParameters.h"
#include "StarRenderingParameters.h"
#include "StarScalabilityParameters.h"
#include "NiagaraDataInterfaceHYGStarCatalog.generated.h"

class UStarCatalog;

UCLASS(Blueprintable, EditInlineNew)
class NIAGARASTARFIELD_API UNiagaraDataInterfaceHYGStarCatalog : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStarCatalog* StarCatalogAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarRenderingParameters RenderingParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPixelStarRenderingParameters PixelRenderingParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarScalabilityParameters ScalabilityParams;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bStarSpawnValuesGPUBufferDirty;
    
public:
    UNiagaraDataInterfaceHYGStarCatalog();
};

