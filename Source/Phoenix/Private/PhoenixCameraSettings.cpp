#include "PhoenixCameraSettings.h"

class APlayerController;
class UObject;

void UPhoenixCameraSettings::SetToggleAim(bool bInToggleAim) {
}

void UPhoenixCameraSettings::SetSpeedFollowCamera(float InFollowSpeed) {
}

void UPhoenixCameraSettings::SetSettingsData(const FPhoenixCameraSettingsData& InSettingsData) {
}

void UPhoenixCameraSettings::SetMotionBlur(bool bInMotionBlur) {
}

void UPhoenixCameraSettings::SetInvertY(bool bInInvertY) {
}

void UPhoenixCameraSettings::SetInvertX(bool bInInvertX) {
}

void UPhoenixCameraSettings::SetInvertFlightY(bool bInInvertFlightY) {
}

void UPhoenixCameraSettings::SetInputSensitivityDefault(float InSensitivity) {
}

void UPhoenixCameraSettings::SetInputSensitivityAiming(float InSensitivity) {
}

void UPhoenixCameraSettings::SetInputAccelerationDefault(float InAcceleration) {
}

void UPhoenixCameraSettings::SetInputAccelerationAiming(float InAcceleration) {
}

void UPhoenixCameraSettings::SetGamepadSouthpaw(bool bInSouthpaw) {
}

void UPhoenixCameraSettings::SetGamepadDeadzone(float InDeadzone) {
}

void UPhoenixCameraSettings::SetGamepadAimingSwitch(bool bInAimingSwitch) {
}

bool UPhoenixCameraSettings::SetFilmGrain(bool bInFilmGrain) {
    return false;
}

void UPhoenixCameraSettings::SetFieldOfViewOffset(float InFieldOfViewOffset) {
}

void UPhoenixCameraSettings::SetDirectorCam_ZoomInputSensitivity(float InSensitivity) {
}

void UPhoenixCameraSettings::SetDirectorCam_ZoomInputAcceleration(float InAcceleration) {
}

void UPhoenixCameraSettings::SetDirectorCam_ZoomFiltering(float InFiltering) {
}

void UPhoenixCameraSettings::SetDirectorCam_TruckInLocalSpace(bool bInValue) {
}

void UPhoenixCameraSettings::SetDirectorCam_SwitchRollAndZoomInput(bool bInValue) {
}

void UPhoenixCameraSettings::SetDirectorCam_RotationInputSensitivity(float InSensitivity) {
}

void UPhoenixCameraSettings::SetDirectorCam_RotationInputAcceleration(float InAcceleration) {
}

void UPhoenixCameraSettings::SetDirectorCam_RotationFiltering(float InFiltering) {
}

void UPhoenixCameraSettings::SetDirectorCam_RollInputSensitivity(float InSensitivity) {
}

void UPhoenixCameraSettings::SetDirectorCam_RollInputAcceleration(float InAcceleration) {
}

void UPhoenixCameraSettings::SetDirectorCam_PedestalInputSensitivity(float InSensitivity) {
}

void UPhoenixCameraSettings::SetDirectorCam_PedestalInputAcceleration(float InAcceleration) {
}

void UPhoenixCameraSettings::SetDirectorCam_PedestalInLocalSpace(bool bInValue) {
}

void UPhoenixCameraSettings::SetDirectorCam_MoveInputSensitivity(float InSensitivity) {
}

void UPhoenixCameraSettings::SetDirectorCam_MoveInputAcceleration(float InAcceleration) {
}

void UPhoenixCameraSettings::SetDirectorCam_MoveFiltering(float InFiltering) {
}

void UPhoenixCameraSettings::SetDirectorCam_FocusDistanceInputSensitivity(float InSensitivity) {
}

void UPhoenixCameraSettings::SetDirectorCam_FocusDistanceInputAcceleration(float InAcceleration) {
}

void UPhoenixCameraSettings::SetDirectorCam_FocusDistanceFiltering(float InFiltering) {
}

void UPhoenixCameraSettings::SetDirectorCam_DollyInLocalSpace(bool bInValue) {
}

void UPhoenixCameraSettings::SetDirectorCam_Aperture(float InAperture) {
}

void UPhoenixCameraSettings::SetDirectorCam_AmbientIntensity(float InIntensity) {
}

void UPhoenixCameraSettings::SetDirectorCam_AmbientFrequency(float InFrequency) {
}

void UPhoenixCameraSettings::SetDepthOfField(bool bInDepthOfField) {
}

void UPhoenixCameraSettings::SetCineCameraShake(bool bInCineCameraShake) {
}

bool UPhoenixCameraSettings::SetChromaticAberration(bool bInChromaticAberration) {
    return false;
}

void UPhoenixCameraSettings::SetCameraShake(float InCameraShake) {
}

void UPhoenixCameraSettings::SetAmountMotionBlur(float InMotionBlurAmount) {
}

void UPhoenixCameraSettings::SetAimAssistStrength(float InStrength) {
}

void UPhoenixCameraSettings::ResetGameplaySettings() {
}

void UPhoenixCameraSettings::ResetDisplaySettings() {
}

void UPhoenixCameraSettings::ResetConsoleDisplaySettings() {
}

void UPhoenixCameraSettings::ResetAccessibilitySettings() {
}

bool UPhoenixCameraSettings::GetToggleAim() {
    return false;
}

float UPhoenixCameraSettings::GetSpeedFollowCamera() {
    return 0.0f;
}

FPhoenixCameraSettingsData UPhoenixCameraSettings::GetSettingsData() {
    return FPhoenixCameraSettingsData{};
}

bool UPhoenixCameraSettings::GetMotionBlur() {
    return false;
}

bool UPhoenixCameraSettings::GetInvertY() {
    return false;
}

bool UPhoenixCameraSettings::GetInvertX() {
    return false;
}

float UPhoenixCameraSettings::GetInputSensitivityDefault() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetInputSensitivityAiming() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetInputAccelerationDefault() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetInputAccelerationAiming() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetGamepadSouthpaw() {
    return false;
}

float UPhoenixCameraSettings::GetGamepadDeadzone() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetGamepadAimingSwitch() {
    return false;
}

bool UPhoenixCameraSettings::GetFlightInvertY() {
    return false;
}

bool UPhoenixCameraSettings::GetFilmGrain() {
    return false;
}

float UPhoenixCameraSettings::GetFieldOfViewOffset() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetDirty() {
    return false;
}

float UPhoenixCameraSettings::GetDirectorCam_ZoomInputSensitivity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_ZoomInputAcceleration() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_ZoomFiltering() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetDirectorCam_TruckInLocalSpace() {
    return false;
}

bool UPhoenixCameraSettings::GetDirectorCam_SwitchRollAndZoomInput() {
    return false;
}

float UPhoenixCameraSettings::GetDirectorCam_RotationInputSensitivity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_RotationInputAcceleration() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_RotationFiltering() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_RollInputSensitivity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_RollInputAcceleration() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_PedestalInputSensitivity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_PedestalInputAcceleration() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetDirectorCam_PedestalInLocalSpace() {
    return false;
}

float UPhoenixCameraSettings::GetDirectorCam_MoveInputSensitivity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_MoveInputAcceleration() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_MoveFiltering() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_FocusDistanceInputSensitivity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_FocusDistanceInputAcceleration() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_FocusDistanceFiltering() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetDirectorCam_DollyInLocalSpace() {
    return false;
}

float UPhoenixCameraSettings::GetDirectorCam_Aperture() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_AmbientIntensity() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetDirectorCam_AmbientFrequency() {
    return 0.0f;
}

bool UPhoenixCameraSettings::GetDepthOfField() {
    return false;
}

bool UPhoenixCameraSettings::GetCineCameraShake() {
    return false;
}

bool UPhoenixCameraSettings::GetChromaticAberration() {
    return false;
}

float UPhoenixCameraSettings::GetCameraShake() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetAppliedFieldOfView(const UObject* InWorldContextObject) {
    return 0.0f;
}

float UPhoenixCameraSettings::GetAmountMotionBlur() {
    return 0.0f;
}

float UPhoenixCameraSettings::GetAimAssistStrength() {
    return 0.0f;
}

void UPhoenixCameraSettings::ApplyToCameraManager(APlayerController* PC) {
}

void UPhoenixCameraSettings::Apply(const UObject* InWorldContextObject) {
}

UPhoenixCameraSettings::UPhoenixCameraSettings() {
    this->bDirty = false;
}

