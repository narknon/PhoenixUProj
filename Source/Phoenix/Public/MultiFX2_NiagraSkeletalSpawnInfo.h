#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersPrimFilter.h"
#include "NiagaraSystemSpawnMultiSkeletalInfo.h"
#include "MultiFX2_NiagraSpawnInfoBase.h"
#include "MultiFX2_NiagraSkeletalSpawnInfo.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraSkeletalSpawnInfo : public UMultiFX2_NiagraSpawnInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersPrimFilter Filter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnMultiSkeletalInfo SpawnInfo;
    
    UMultiFX2_NiagraSkeletalSpawnInfo();
};

