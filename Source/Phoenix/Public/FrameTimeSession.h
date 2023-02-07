#pragma once
#include "CoreMinimal.h"
#include "SessionTracker.h"
#include "FrameTimeSession.generated.h"

UCLASS(Blueprintable)
class UFrameTimeSession : public USessionTracker {
    GENERATED_BODY()
public:
    UFrameTimeSession();
    UFUNCTION(BlueprintCallable)
    void Tick();
    
};

