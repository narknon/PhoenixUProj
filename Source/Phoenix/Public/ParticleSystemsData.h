#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemTrigger.h"
#include "ParticleSystemTrigger.h"
#include "ParticleSystemsData.generated.h"

USTRUCT(BlueprintType)
struct FParticleSystemsData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FParticleSystemTrigger> ParticleSystems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraSystemTrigger> NiagaraSystems;
    
    PHOENIX_API FParticleSystemsData();
};

