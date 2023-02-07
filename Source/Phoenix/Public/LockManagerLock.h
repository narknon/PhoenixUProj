#pragma once
#include "CoreMinimal.h"
#include "ELockStates.h"
#include "LockManagerLock.generated.h"

USTRUCT(BlueprintType)
struct FLockManagerLock {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELockStates LockState;
    
    PHOENIX_API FLockManagerLock();
};

