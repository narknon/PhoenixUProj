#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemSpawnAttachedInfo.h"
#include "NiagaraSystemSpawnAttachedPointInfo.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraSystemSpawnAttachedPointInfo : public FNiagaraSystemSpawnAttachedInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailOnAttachPointMissing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeepSearchComponents;
    
    FNiagaraSystemSpawnAttachedPointInfo();
};

