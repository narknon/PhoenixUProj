#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersPrimFilter.h"
#include "NiagaraSystemSpawnAttachedInfo.h"
#include "MultiFX2_NiagraSpawnInfoBase.h"
#include "MultiFX2_NiagraPrimSpawnInfo.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraPrimSpawnInfo : public UMultiFX2_NiagraSpawnInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersPrimFilter Filter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnAttachedInfo SpawnInfo;
    
    UMultiFX2_NiagraPrimSpawnInfo();
};

