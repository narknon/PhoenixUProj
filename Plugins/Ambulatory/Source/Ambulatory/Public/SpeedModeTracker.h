#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETargetSpeedMode.h"
#include "ETargetSpeedPriority.h"
#include "SpeedModeTracker.generated.h"

UCLASS(Blueprintable, DefaultToInstanced)
class AMBULATORY_API USpeedModeTracker : public UObject {
    GENERATED_BODY()
public:
    USpeedModeTracker();
    UFUNCTION(BlueprintCallable)
    void SetTargetSpeedMode(ETargetSpeedMode::Type InSpeedMode, ETargetSpeedPriority::Type InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable)
    void SetBaseTargetSpeedMode(ETargetSpeedMode::Type InSpeedMode);
    
    UFUNCTION(BlueprintCallable)
    ETargetSpeedMode::Type GetTargetSpeedMode();
    
    UFUNCTION(BlueprintCallable)
    ETargetSpeedMode::Type GetBaseTargetSpeedMode();
    
    UFUNCTION(BlueprintCallable)
    void ClearTargetSpeedMode(ETargetSpeedPriority::Type InPriority, bool bBroadcastChange);
    
};

