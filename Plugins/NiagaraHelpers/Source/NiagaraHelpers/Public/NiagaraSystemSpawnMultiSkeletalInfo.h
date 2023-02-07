#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemSpawnMultiInfo.h"
#include "NiagaraSystemSpawnMultiSkeletalInfo.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraSystemSpawnMultiSkeletalInfo : public FNiagaraSystemSpawnMultiInfo {
    GENERATED_BODY()
public:
    FNiagaraSystemSpawnMultiSkeletalInfo();
};

