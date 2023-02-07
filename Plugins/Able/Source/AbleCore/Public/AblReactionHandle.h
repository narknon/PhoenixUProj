#pragma once
#include "CoreMinimal.h"
#include "AblReactionHandle.generated.h"

USTRUCT(BlueprintType)
struct FAblReactionHandle {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint64 Handle;
    
public:
    ABLECORE_API FAblReactionHandle();
};

