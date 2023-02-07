#pragma once
#include "CoreMinimal.h"
#include "WorldFXFullTracker.generated.h"

class UWorldFXOctreeFX;

USTRUCT(BlueprintType)
struct FWorldFXFullTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorldFXOctreeFX> SFX;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorldFXOctreeFX> CascadeFX;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorldFXOctreeFX> NiagaraFX;
    
    WORLDFX_API FWorldFXFullTracker();
};

