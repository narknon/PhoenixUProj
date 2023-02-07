#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemSpawnMultiInfo.h"
#include "NiagaraSystemSpawnMultiStaticInfo.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraSystemSpawnMultiStaticInfo : public FNiagaraSystemSpawnMultiInfo {
    GENERATED_BODY()
public:
    FNiagaraSystemSpawnMultiStaticInfo();
};

