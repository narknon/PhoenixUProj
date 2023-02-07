#pragma once
#include "CoreMinimal.h"
#include "SessionTracker.h"
#include "LockPlayerSession.generated.h"

UCLASS(Blueprintable)
class ULockPlayerSession : public USessionTracker {
    GENERATED_BODY()
public:
    ULockPlayerSession();
    UFUNCTION(BlueprintCallable)
    void Tick();
    
};

