#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NiagaraSystemSpawnBoundsSpawnRate.h"
#include "NiagaraSystemSpawnInfo.h"
#include "NiagaraSystemSpawnAttachedInfo.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraSystemSpawnAttachedInfo : public FNiagaraSystemSpawnInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAttachLocation::Type> AttachLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnBoundsSpawnRate BoundsSpawnRateAdjustment;
    
    FNiagaraSystemSpawnAttachedInfo();
};

