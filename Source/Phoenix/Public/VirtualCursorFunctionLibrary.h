#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VirtualCursorFunctionLibrary.generated.h"

class APlayerController;

UCLASS(Blueprintable)
class UVirtualCursorFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UVirtualCursorFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetCursorPostion(APlayerController* PC, float nx, float ny);
    
    UFUNCTION(BlueprintCallable)
    static void SetCursorPositionDirect(APlayerController* PC, float nx, float ny);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllowMouseClickInput(bool Allow);
    
    UFUNCTION(BlueprintCallable)
    static bool IsVirtualCursorEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCursorOverInteractableWidget();
    
    UFUNCTION(BlueprintCallable)
    static bool GetIsUsingVirtualCursor();
    
    UFUNCTION(BlueprintCallable)
    static bool GetIsStickTouched();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetCursorPostion();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetCursorPositionDirect();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetAnalogTriggerValues();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetAnalogRightValues();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetAnalogLeftValues();
    
    UFUNCTION(BlueprintCallable)
    static void EnableVirtualCursor(APlayerController* PC);
    
    UFUNCTION(BlueprintCallable)
    static void DisableVirtualCursor(APlayerController* PC);
    
};

