#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "NiagaraSystemSpawnInfoOverride.h"
#include "NiagaraSystemSpawnAttachedInfoOverride.generated.h"

USTRUCT(BlueprintType)
struct FNiagaraSystemSpawnAttachedInfoOverride : public FNiagaraSystemSpawnInfoOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_AttachLocation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAttachLocation::Type> AttachLocation;
    
    NIAGARAHELPERS_API FNiagaraSystemSpawnAttachedInfoOverride();
};

