#pragma once
#include "CoreMinimal.h"
#include "DuelTechnique.h"
#include "DuelTechnique_TimedEncounter.generated.h"

class UObject;

UCLASS(Blueprintable)
class UDuelTechnique_TimedEncounter : public UDuelTechnique {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ControllerOuter;
    
public:
    UDuelTechnique_TimedEncounter();
private:
    UFUNCTION(BlueprintCallable)
    void TimerTick();
    
public:
    UFUNCTION(BlueprintCallable)
    bool InitializeImpl();
    
};

