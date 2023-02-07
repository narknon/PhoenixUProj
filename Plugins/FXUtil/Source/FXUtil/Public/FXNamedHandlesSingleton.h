#pragma once
#include "CoreMinimal.h"
#include "PerWorldFXNamedHandles.h"
#include "FXNamedHandlesSingleton.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FFXNamedHandlesSingleton {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FPerWorldFXNamedHandles> Handles;
    
    FXUTIL_API FFXNamedHandlesSingleton();
};

