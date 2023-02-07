#pragma once
#include "CoreMinimal.h"
#include "WorldFXCullDistance.h"
#include "WorldFXMaterialOverrideList.h"
#include "WorldFXNiagaraSystemAdvancedOptions.h"
#include "WorldFXNiagaraSystem.generated.h"

class UNiagaraSystem;
class UWorldFXNiagaraSystemInitializer;

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXNiagaraSystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> NiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXNiagaraSystemInitializer* Initializer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXMaterialOverrideList Materials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXCullDistance CullDistance;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXNiagaraSystemAdvancedOptions AdvancedOptions;
    
    FWorldFXNiagaraSystem();
};

