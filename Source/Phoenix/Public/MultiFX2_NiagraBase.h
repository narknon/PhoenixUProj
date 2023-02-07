#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_NiagraBase.generated.h"

class UMultiFX2_NiagraPropertyBase;
class UMultiFX2_NiagraSpawnInfoBase;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraBase : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, NoClear, meta=(AllowPrivateAccess=true))
    UMultiFX2_NiagraSpawnInfoBase* SpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_NiagraPropertyBase*> NiagaraProperties;
    
public:
    UMultiFX2_NiagraBase();
};

