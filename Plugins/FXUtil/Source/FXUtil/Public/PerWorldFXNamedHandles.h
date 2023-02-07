#pragma once
#include "CoreMinimal.h"
#include "FXNamedHandles.h"
#include "PerWorldFXNamedHandles.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FPerWorldFXNamedHandles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFXNamedHandles Global;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UObject>, FFXNamedHandles> Targets;
    
    FXUTIL_API FPerWorldFXNamedHandles();
};

