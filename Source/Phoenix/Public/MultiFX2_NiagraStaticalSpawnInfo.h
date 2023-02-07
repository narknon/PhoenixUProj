#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersPrimFilter.h"
#include "NiagaraSystemSpawnMultiStaticInfo.h"
#include "MultiFX2_NiagraSpawnInfoBase.h"
#include "MultiFX2_NiagraStaticalSpawnInfo.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraStaticalSpawnInfo : public UMultiFX2_NiagraSpawnInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersPrimFilter Filter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnMultiStaticInfo SpawnInfo;
    
    UMultiFX2_NiagraStaticalSpawnInfo();
};

