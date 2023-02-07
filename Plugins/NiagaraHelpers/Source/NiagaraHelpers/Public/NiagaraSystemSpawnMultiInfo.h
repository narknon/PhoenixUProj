#pragma once
#include "CoreMinimal.h"
#include "ENiagaraHelpersMultiSpawnRateType.h"
#include "NiagaraSystemSpawnAttachedInfo.h"
#include "NiagaraSystemSpawnMultiInfo.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraSystemSpawnMultiInfo : public FNiagaraSystemSpawnAttachedInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideMeshVar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnRateVar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnRateCutoffPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENiagaraHelpersMultiSpawnRateType SpawnRateMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCombineBoundsAndMultiSpawnRates;
    
    FNiagaraSystemSpawnMultiInfo();
};

