#pragma once
#include "CoreMinimal.h"
#include "DuelTechnique.h"
#include "DuelTechnique_TimedJuggle.generated.h"

class UObject;

UCLASS(Blueprintable)
class UDuelTechnique_TimedJuggle : public UDuelTechnique {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ControllerOuter;
    
public:
    UDuelTechnique_TimedJuggle();
private:
    UFUNCTION(BlueprintCallable)
    void TimerTick();
    
};

