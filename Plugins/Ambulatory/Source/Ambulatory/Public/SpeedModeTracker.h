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
    void SetTargetSpeedMode(TEnumAsByte<ETargetSpeedMode::Type> InSpeedMode, TEnumAsByte<ETargetSpeedPriority::Type> InPriority, bool bBroadcastChange);
    
    UFUNCTION(BlueprintCallable)
    void SetBaseTargetSpeedMode(TEnumAsByte<ETargetSpeedMode::Type> InSpeedMode);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<ETargetSpeedMode::Type> GetTargetSpeedMode();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<ETargetSpeedMode::Type> GetBaseTargetSpeedMode();
    
    UFUNCTION(BlueprintCallable)
    void ClearTargetSpeedMode(TEnumAsByte<ETargetSpeedPriority::Type> InPriority, bool bBroadcastChange);
    
};

