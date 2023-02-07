#pragma once
#include "CoreMinimal.h"
#include "MultiFXHandle.generated.h"

USTRUCT(BlueprintType)
struct FMultiFXHandle {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint64 Handle;
    
public:
    PHOENIX_API FMultiFXHandle();
};

