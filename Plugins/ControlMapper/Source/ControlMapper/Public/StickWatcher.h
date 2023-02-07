#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseWatcher.h"
#include "StickWatcher.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UStickWatcher : public UBaseWatcher {
    GENERATED_BODY()
public:
    UStickWatcher();
    UFUNCTION(BlueprintCallable)
    void StickY(float AxisVal);
    
    UFUNCTION(BlueprintCallable)
    void StickX(float AxisVal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector2D GetInputAxes();
    
    UFUNCTION(BlueprintCallable)
    void ActionStop();
    
    UFUNCTION(BlueprintCallable)
    void ActionStart();
    
    UFUNCTION(BlueprintCallable)
    void ActionCancel();
    
};

