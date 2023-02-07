#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PhoenixCameraSettingsData.h"
#include "PhoenixCameraSettings.generated.h"

class APlayerController;

UCLASS(Blueprintable)
class UPhoenixCameraSettings : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPhoenixCameraSettingsData SettingsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDirty;
    
public:
    UPhoenixCameraSettings();
    UFUNCTION(BlueprintCallable)
    static void SetToggleAim(bool bInToggleAim);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpeedFollowCamera(float InFollowSpeed);
    
    UFUNCTION(BlueprintCallable)
    static void SetSettingsData(const FPhoenixCameraSettingsData& InSettingsData);
    
    UFUNCTION(BlueprintCallable)
    static void SetMotionBlur(bool bInMotionBlur);
    
    UFUNCTION(BlueprintCallable)
    static void SetInvertY(bool bInInvertY);
    
    UFUNCTION(BlueprintCallable)
    static void SetInvertX(bool bInInvertX);
    
    UFUNCTION(BlueprintCallable)
    static void SetInvertFlightY(bool bInInvertFlightY);
    
    UFUNCTION(BlueprintCallable)
    static void SetInputSensitivityDefault(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetInputSensitivityAiming(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetInputAccelerationDefault(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetInputAccelerationAiming(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetGamepadSouthpaw(bool bInSouthpaw);
    
    UFUNCTION(BlueprintCallable)
    static void SetGamepadDeadzone(float InDeadzone);
    
    UFUNCTION(BlueprintCallable)
    static void SetGamepadAimingSwitch(bool bInAimingSwitch);
    
    UFUNCTION(BlueprintCallable)
    static bool SetFilmGrain(bool bInFilmGrain);
    
    UFUNCTION(BlueprintCallable)
    static void SetFieldOfViewOffset(float InFieldOfViewOffset);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_ZoomInputSensitivity(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_ZoomInputAcceleration(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_ZoomFiltering(float InFiltering);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_TruckInLocalSpace(bool bInValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_SwitchRollAndZoomInput(bool bInValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_RotationInputSensitivity(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_RotationInputAcceleration(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_RotationFiltering(float InFiltering);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_RollInputSensitivity(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_RollInputAcceleration(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_PedestalInputSensitivity(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_PedestalInputAcceleration(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_PedestalInLocalSpace(bool bInValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_MoveInputSensitivity(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_MoveInputAcceleration(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_MoveFiltering(float InFiltering);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_FocusDistanceInputSensitivity(float InSensitivity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_FocusDistanceInputAcceleration(float InAcceleration);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_FocusDistanceFiltering(float InFiltering);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_DollyInLocalSpace(bool bInValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_Aperture(float InAperture);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_AmbientIntensity(float InIntensity);
    
    UFUNCTION(BlueprintCallable)
    static void SetDirectorCam_AmbientFrequency(float InFrequency);
    
    UFUNCTION(BlueprintCallable)
    static void SetDepthOfField(bool bInDepthOfField);
    
    UFUNCTION(BlueprintCallable)
    static void SetCineCameraShake(bool bInCineCameraShake);
    
    UFUNCTION(BlueprintCallable)
    static bool SetChromaticAberration(bool bInChromaticAberration);
    
    UFUNCTION(BlueprintCallable)
    static void SetCameraShake(float InCameraShake);
    
    UFUNCTION(BlueprintCallable)
    static void SetAmountMotionBlur(float InMotionBlurAmount);
    
    UFUNCTION(BlueprintCallable)
    static void SetAimAssistStrength(float InStrength);
    
    UFUNCTION(BlueprintCallable)
    static void ResetGameplaySettings();
    
    UFUNCTION(BlueprintCallable)
    static void ResetDisplaySettings();
    
    UFUNCTION(BlueprintCallable)
    static void ResetConsoleDisplaySettings();
    
    UFUNCTION(BlueprintCallable)
    static void ResetAccessibilitySettings();
    
    UFUNCTION(BlueprintCallable)
    static bool GetToggleAim();
    
    UFUNCTION(BlueprintCallable)
    static float GetSpeedFollowCamera();
    
    UFUNCTION(BlueprintCallable)
    static FPhoenixCameraSettingsData GetSettingsData();
    
    UFUNCTION(BlueprintCallable)
    static bool GetMotionBlur();
    
    UFUNCTION(BlueprintCallable)
    static bool GetInvertY();
    
    UFUNCTION(BlueprintCallable)
    static bool GetInvertX();
    
    UFUNCTION(BlueprintCallable)
    static float GetInputSensitivityDefault();
    
    UFUNCTION(BlueprintCallable)
    static float GetInputSensitivityAiming();
    
    UFUNCTION(BlueprintCallable)
    static float GetInputAccelerationDefault();
    
    UFUNCTION(BlueprintCallable)
    static float GetInputAccelerationAiming();
    
    UFUNCTION(BlueprintCallable)
    static bool GetGamepadSouthpaw();
    
    UFUNCTION(BlueprintCallable)
    static float GetGamepadDeadzone();
    
    UFUNCTION(BlueprintCallable)
    static bool GetGamepadAimingSwitch();
    
    UFUNCTION(BlueprintCallable)
    static bool GetFlightInvertY();
    
    UFUNCTION(BlueprintCallable)
    static bool GetFilmGrain();
    
    UFUNCTION(BlueprintCallable)
    static float GetFieldOfViewOffset();
    
    UFUNCTION(BlueprintCallable)
    static bool GetDirty();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_ZoomInputSensitivity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_ZoomInputAcceleration();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_ZoomFiltering();
    
    UFUNCTION(BlueprintCallable)
    static bool GetDirectorCam_TruckInLocalSpace();
    
    UFUNCTION(BlueprintCallable)
    static bool GetDirectorCam_SwitchRollAndZoomInput();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_RotationInputSensitivity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_RotationInputAcceleration();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_RotationFiltering();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_RollInputSensitivity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_RollInputAcceleration();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_PedestalInputSensitivity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_PedestalInputAcceleration();
    
    UFUNCTION(BlueprintCallable)
    static bool GetDirectorCam_PedestalInLocalSpace();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_MoveInputSensitivity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_MoveInputAcceleration();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_MoveFiltering();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_FocusDistanceInputSensitivity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_FocusDistanceInputAcceleration();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_FocusDistanceFiltering();
    
    UFUNCTION(BlueprintCallable)
    static bool GetDirectorCam_DollyInLocalSpace();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_Aperture();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_AmbientIntensity();
    
    UFUNCTION(BlueprintCallable)
    static float GetDirectorCam_AmbientFrequency();
    
    UFUNCTION(BlueprintCallable)
    static bool GetDepthOfField();
    
    UFUNCTION(BlueprintCallable)
    static bool GetCineCameraShake();
    
    UFUNCTION(BlueprintCallable)
    static bool GetChromaticAberration();
    
    UFUNCTION(BlueprintCallable)
    static float GetCameraShake();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static float GetAppliedFieldOfView(const UObject* InWorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static float GetAmountMotionBlur();
    
    UFUNCTION(BlueprintCallable)
    static float GetAimAssistStrength();
    
    UFUNCTION(BlueprintCallable)
    static void ApplyToCameraManager(APlayerController* PC);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static void Apply(const UObject* InWorldContextObject);
    
};

