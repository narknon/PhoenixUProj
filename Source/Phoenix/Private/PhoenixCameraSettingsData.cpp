#include "PhoenixCameraSettingsData.h"

FPhoenixCameraSettingsData::FPhoenixCameraSettingsData() {
    this->FieldOfViewOffset = 0.00f;
    this->InputSensitivityDefault = 0.00f;
    this->InputSensitivityAiming = 0.00f;
    this->InputAccelerationDefault = 0.00f;
    this->InputAccelerationAiming = 0.00f;
    this->AimAssistStrength = 0.00f;
    this->GamepadDeadzone = 0.00f;
    this->bGamepadSouthpaw = false;
    this->bGamepadAimingSwitch = false;
    this->bInvertX = false;
    this->bInvertY = false;
    this->bInvertFlightY = false;
    this->bToggleAim = false;
    this->FollowSpeed = 0.00f;
    this->CameraShake = 0.00f;
    this->bCineCameraShake = false;
    this->bDepthOfField = false;
    this->bChromaticAberration = false;
    this->bFilmGrain = false;
    this->bMotionBlur = false;
    this->MotionBlurAmount = 0.00f;
    this->DirectorCam_RotationInputSensitivity = 0.00f;
    this->DirectorCam_RotationInputAcceleration = 0.00f;
    this->DirectorCam_RollInputSensitivity = 0.00f;
    this->DirectorCam_RollInputAcceleration = 0.00f;
    this->DirectorCam_RotationFiltering = 0.00f;
    this->DirectorCam_MoveInputSensitivity = 0.00f;
    this->DirectorCam_MoveInputAcceleration = 0.00f;
    this->DirectorCam_PedestalInputSensitivity = 0.00f;
    this->DirectorCam_PedestalInputAcceleration = 0.00f;
    this->DirectorCam_MoveFiltering = 0.00f;
    this->DirectorCam_ZoomInputSensitivity = 0.00f;
    this->DirectorCam_ZoomInputAcceleration = 0.00f;
    this->DirectorCam_ZoomFiltering = 0.00f;
    this->DirectorCam_FocusDistanceInputSensitivity = 0.00f;
    this->DirectorCam_FocusDistanceInputAcceleration = 0.00f;
    this->DirectorCam_FocusDistanceFiltering = 0.00f;
    this->DirectorCam_Aperture = 0.00f;
    this->DirectorCam_AmbientIntensity = 0.00f;
    this->DirectorCam_AmbientFrequency = 0.00f;
    this->bDirectorCam_DollyInLocalSpace = false;
    this->bDirectorCam_TruckInLocalSpace = false;
    this->bDirectorCam_PedestalInLocalSpace = false;
    this->bDirectorCam_SwitchRollAndZoomInput = false;
}

