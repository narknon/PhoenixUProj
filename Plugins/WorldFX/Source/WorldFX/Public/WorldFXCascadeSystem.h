#pragma once
#include "CoreMinimal.h"
#include "WorldFXCascadeSystemAdvancedOptions.h"
#include "WorldFXCascadeSystemParam.h"
#include "WorldFXCullDistance.h"
#include "WorldFXMaterialOverrideList.h"
#include "WorldFXCascadeSystem.generated.h"

class UParticleSystem;
class UWorldFXCascadeInstanceParametersBase;

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> ParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXMaterialOverrideList Materials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFXCascadeSystemParam> InstanceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXCascadeInstanceParametersBase* NewInstanceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXCullDistance CullDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXCascadeSystemAdvancedOptions AdvancedOptions;
    
    FWorldFXCascadeSystem();
};

