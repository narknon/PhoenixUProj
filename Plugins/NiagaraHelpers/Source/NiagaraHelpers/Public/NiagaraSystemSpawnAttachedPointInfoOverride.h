#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemSpawnAttachedInfoOverride.h"
#include "NiagaraSystemSpawnAttachedPointInfoOverride.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraSystemSpawnAttachedPointInfoOverride : public FNiagaraSystemSpawnAttachedInfoOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_AttachPoint: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_FailOnAttachPointMissing: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_DeepSearchComponents: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailOnAttachPointMissing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeepSearchComponents;
    
    NIAGARAHELPERS_API FNiagaraSystemSpawnAttachedPointInfoOverride();
};

