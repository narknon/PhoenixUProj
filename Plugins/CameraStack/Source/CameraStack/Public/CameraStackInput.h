#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "ELastCameraInput.h"
#include "CameraStackInput.generated.h"

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackInput : public UObject {
    GENERATED_BODY()
public:
    UCameraStackInput();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLooking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyMouseLookInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnyLookInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetZoom() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetWalk(bool bInvertX, bool bInvertY) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetTilt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRoll() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetResetPressed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetQuickTurnPressed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPedestal() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetMouseLook(bool bInvertX, bool bInvertY) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetLook(bool bInvertX, bool bInvertY) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELastCameraInput GetLastCameraInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFocusDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetDollyAndTruck() const;
    
};

