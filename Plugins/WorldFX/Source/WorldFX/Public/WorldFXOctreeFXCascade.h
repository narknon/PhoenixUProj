#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXCascadeSystemAdvancedOptions.h"
#include "WorldFXMaterialOverrideList.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXSpawnOverridesFinal.h"
#include "WorldFXOctreeFXCascade.generated.h"

class UParticleSystem;
class UParticleSystemComponent;
class UWorldFXCascadeInstanceParametersBase;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXCascade : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> ParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXMaterialOverrideList Materials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXCascadeInstanceParametersBase* InstanceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXSpawnOverridesFinal SpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXCascadeSystemAdvancedOptions AdvancedOptions;
    
    UWorldFXOctreeFXCascade();
};

