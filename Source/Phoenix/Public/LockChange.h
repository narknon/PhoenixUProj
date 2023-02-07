#pragma once
#include "CoreMinimal.h"
#include "ELockStates.h"
#include "LockChange.generated.h"

USTRUCT(BlueprintType)
struct FLockChange {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELockStates newLockState;
    
    PHOENIX_API FLockChange();
};

