#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OptionalTriplet.h"
#include "CameraStackLimitsInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UCameraStackLimitsInterface : public UInterface {
    GENERATED_BODY()
};

class ICameraStackLimitsInterface : public IInterface {
    GENERATED_BODY()
public:
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetRotationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetFocusDistanceLimits(float& OutMin, float& OutMax) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetFieldOfViewLimits(float& OutMin, float& OutMax) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetCameraSpaceTranslationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetCameraSpaceRotationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetArmOriginLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetArmLengthLimits(float& OutMin, float& OutMax) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetApertureLimits(float& OutMin, float& OutMax) const;
    
};

