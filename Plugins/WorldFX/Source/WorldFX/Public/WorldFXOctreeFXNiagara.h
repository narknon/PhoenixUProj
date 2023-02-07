#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXMaterialOverrideList.h"
#include "WorldFXNiagaraSystemAdvancedOptions.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXSpawnOverridesFinal.h"
#include "WorldFXOctreeFXNiagara.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class UWorldFXNiagaraSystemInitializer;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXNiagara : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> NiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXNiagaraSystemInitializer* Initializer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXMaterialOverrideList Materials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXSpawnOverridesFinal SpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXNiagaraSystemAdvancedOptions AdvancedOptions;
    
    UWorldFXOctreeFXNiagara();
};

