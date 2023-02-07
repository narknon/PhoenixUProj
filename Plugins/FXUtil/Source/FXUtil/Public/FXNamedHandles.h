#pragma once
#include "CoreMinimal.h"
#include "MultiFX2Handle.h"
#include "FXNamedHandles.generated.h"

USTRUCT(BlueprintType)
struct FFXNamedHandles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FMultiFX2Handle> NamedHandles;
    
    FXUTIL_API FFXNamedHandles();
};

