#pragma once
#include "CoreMinimal.h"
#include "GameLogicBoolBase.h"
#include "GameLogicVar_Timer.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_Timer : public UGameLogicBoolBase {
    GENERATED_BODY()
public:
    UGameLogicVar_Timer();
    UFUNCTION(BlueprintCallable)
    void TimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void SetTimerValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTimerPause(bool bInPaused);
    
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(bool bValue);
    
    UFUNCTION(BlueprintCallable)
    bool IsTimerPaused();
    
    UFUNCTION(BlueprintCallable)
    float GetTimerValue();
    
};

