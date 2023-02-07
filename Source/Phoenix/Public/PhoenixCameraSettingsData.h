#pragma once
#include "CoreMinimal.h"
#include "PhoenixCameraSettingsData.generated.h"

USTRUCT(BlueprintType)
struct FPhoenixCameraSettingsData {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float FieldOfViewOffset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float InputSensitivityDefault;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float InputSensitivityAiming;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float InputAccelerationDefault;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float InputAccelerationAiming;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float AimAssistStrength;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float GamepadDeadzone;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bGamepadSouthpaw;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bGamepadAimingSwitch;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bInvertX;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bInvertY;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bInvertFlightY;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bToggleAim;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float FollowSpeed;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CameraShake;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bCineCameraShake;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDepthOfField;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bChromaticAberration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bFilmGrain;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bMotionBlur;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MotionBlurAmount;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_RotationInputSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_RotationInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_RollInputSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_RollInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_RotationFiltering;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_MoveInputSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_MoveInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_PedestalInputSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_PedestalInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_MoveFiltering;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_ZoomInputSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_ZoomInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_ZoomFiltering;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_FocusDistanceInputSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_FocusDistanceInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_FocusDistanceFiltering;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_Aperture;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_AmbientIntensity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float DirectorCam_AmbientFrequency;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDirectorCam_DollyInLocalSpace;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDirectorCam_TruckInLocalSpace;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDirectorCam_PedestalInLocalSpace;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bDirectorCam_SwitchRollAndZoomInput;
    
public:
    PHOENIX_API FPhoenixCameraSettingsData();
};

