#pragma once
#include "CoreMinimal.h"
#include "SessionTracker.h"
#include "StreamTimeSession.generated.h"

UCLASS(Blueprintable)
class UStreamTimeSession : public USessionTracker {
    GENERATED_BODY()
public:
    UStreamTimeSession();
    UFUNCTION(BlueprintCallable)
    void Tick();
    
};

