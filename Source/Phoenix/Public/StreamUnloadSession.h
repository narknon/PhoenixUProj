#pragma once
#include "CoreMinimal.h"
#include "SessionTracker.h"
#include "StreamUnloadSession.generated.h"

UCLASS(Blueprintable)
class UStreamUnloadSession : public USessionTracker {
    GENERATED_BODY()
public:
    UStreamUnloadSession();
    UFUNCTION(BlueprintCallable)
    void Tick();
    
};

