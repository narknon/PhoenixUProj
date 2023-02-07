#pragma once
#include "CoreMinimal.h"
#include "WorldFXTracker.generated.h"

class UWorldFXOctreeFX;

USTRUCT(BlueprintType)
struct FWorldFXTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorldFXOctreeFX> FX;
    
    WORLDFX_API FWorldFXTracker();
};

