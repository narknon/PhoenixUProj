#pragma once
#include "CoreMinimal.h"
#include "EHighContrastMode.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/GameUserSettings.h"
#include "Rendering/RenderingCommon.h"
#include "AutoTargetCameraFocusChangedDelegate.h"
#include "EAntiAliasingMode.h"
#include "EDifficulty.h"
#include "ENvidiaLatencyMode.h"
#include "EUpscaleMode.h"
#include "GraphicsAdapterDesc.h"
#include "NvidiaLatencyModeInfo.h"
#include "PerformanceModeChangedDelegate.h"
#include "PhoenixCameraSettingsData.h"
#include "PhoenixGameSettings.generated.h"

class UObject;
class UPhoenixGameSettings;
class UPopupScreen;

UCLASS(Blueprintable)
class PHOENIX_API UPhoenixGameSettings : public UGameUserSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EffectsSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MusicSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VoiceSoundVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SoundMuted;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MonoAudio;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DynamicRange;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MasteringSuite;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableRaytracingShadows;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableRaytracingReflections;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableRaytracingAO;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PerformanceMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFrameRateUncapped;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPhoenixCameraSettingsData CameraSettings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MenuReaderEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MenuReaderVoiceID;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MenuReaderVoiceDescription;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MenuReaderVoiceGender;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MenuReaderVolume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EColorVisionDeficiency ColorVisionDeficiencyType;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MiniMapSize;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MiniMapOpacity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PathLineEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AccessibilityAudioCueOpacity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AccessibilityAudioCueScale;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseMinimalHud;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowTargetHighlights;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowTargetName;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowHudBeacons;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowNotificationElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowXPElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowMissionElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowSpellElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowMeterElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowMapElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowTargetElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowSpecialNotificationElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowTutorialElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowToolWheelElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowEnemyDamageElements;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowBeastControls;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FontSizeOffset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FontIndex;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HighContrastMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AudioVisualizer;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableKeyboardSprintWalkToggle;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAccessibilitySpellToggle;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SubtitlesEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ControllerRumble;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RGBPeripheralsEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysUseCameraAiming;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString INILanguageSetting;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SwitchTextLanguageSetting;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TiltControls;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TiltSensitivity;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUpscaleModeModified;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUpscaleMode UpscaleMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpscaleSoftness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAntiAliasingMode AntiAliasingMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAntiAliasingMode DefaultAntiAliasingMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENvidiaLatencyMode NvidiaLatencyMode;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NvidiaFrameGeneration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Brightness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinToneMapLuminance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidToneMapLuminance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxToneMapLuminance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UIBrightness;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutomaticHDRCalibration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MonitorIdx;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHardwareBenchmarkApplied;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GPUConfigPreset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecViewDistanceQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecAntiAliasingQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecShadowQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecPostProcessQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecTextureQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecEffectsQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecFoliageQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecShadingQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecFogQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecSkyQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecPopulationQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RecRaytracingQuality;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAltTooltipsEnabled;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseOnFocusLoss;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrameRateLimitMinimized;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 SubVersion;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformanceModeChanged PerformanceModeChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAutoTargetCameraFocusChanged AutoTargetCameraFocusChangedDelegate;
    
public:
    UPhoenixGameSettings();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void TriggerAutoReboot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool TestHighContrastMode(EHighContrastMode inContrastMode);
    
    UFUNCTION(BlueprintCallable)
    UPopupScreen* ShowRaytracingRebootPopup();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowRGBPeripheralsButton();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldControllerRumble();
    
    UFUNCTION(BlueprintCallable)
    void SetVoiceSoundVolume(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetUseMinimalHud(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetUpscaleSoftness(float NewSharpness);
    
    UFUNCTION(BlueprintCallable)
    void SetUpscaleMode(EUpscaleMode UpscaleModeInput);
    
    UFUNCTION(BlueprintCallable)
    void SetUncapFrameRate(bool InUncapFrameRate);
    
    UFUNCTION(BlueprintCallable)
    void SetTiltSensitivity(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetTiltControls(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    static void SetSwitchTextLanguage(const FString& Lang);
    
    UFUNCTION(BlueprintCallable)
    void SetSubtitlesEnabled(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetSoundMuted(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetSkyQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetShowXPElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowTutorialElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowToolWheelElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowTargetName(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowTargetHighlights(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowTargetElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowSpellElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowSpecialNotificationElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowNotificationElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowMissionElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowMeterElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowMapElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowHudBeacons(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowEnemyDamageElements(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetShowBeastControls(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    bool SetSelectedMonitor(int32 SelectedMonitorIdx, bool bForceFullscreen);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedGPU(const FGraphicsAdapterDesc& GpuDesc);
    
    UFUNCTION(BlueprintCallable)
    void SetRGBPeripheralsEnabled(bool NewVal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetRaytracingSupported(const bool bShouldSupport) const;
    
    UFUNCTION(BlueprintCallable)
    void SetRaytracingShadows(bool bInEnableRaytracingShadows);
    
    UFUNCTION(BlueprintCallable)
    void SetRaytracingReflections(bool bInEnableRaytracingReflections);
    
    UFUNCTION(BlueprintCallable)
    void SetRaytracingQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetRaytracingAmbientOcclusion(bool bInEnableRaytracingAO);
    
    UFUNCTION(BlueprintCallable)
    void SetPopulationQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetPerformanceMode(const FString& InPerformanceMode);
    
    UFUNCTION(BlueprintCallable)
    void SetPauseOnFocusLoss(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetNvidiaLatencyMode(ENvidiaLatencyMode InMode);
    
    UFUNCTION(BlueprintCallable)
    void SetNvidiaFrameGeneration(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetMusicSoundVolume(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetMonoAudio(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapSize(int32 Size);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapPathEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapOpacity(float Opacity);
    
    UFUNCTION(BlueprintCallable)
    void SetMenuReaderVolume(float InVolume);
    
    UFUNCTION(BlueprintCallable)
    void SetMenuReaderVoice(const FString& InVoiceID, const FString& InDescription, const FString& InGender);
    
    UFUNCTION(BlueprintCallable)
    void SetMenuReaderEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetMasteringSuite(const FString& NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetINILanguageSetting(const FString& NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreConfirmVideoMode(const bool bIgnore);
    
    UFUNCTION(BlueprintCallable)
    void SetHighContrastModeBits(int32 inContrastMode);
    
    UFUNCTION(BlueprintCallable)
    void SetHighContrastMode(EHighContrastMode inContrastMode);
    
    UFUNCTION(BlueprintCallable)
    void SetHideNonCinematicElements(bool bHide, const UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    bool SetHDRToneMapParameters(bool bAutomatic, float NewMinToneMapLuminance, float NewMidToneMapLuminance, float NewMaxToneMapLuminance, float NewUIBrightness);
    
    UFUNCTION(BlueprintCallable)
    void SetFontSizeOffset(int32 NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetFontIndex(int32 NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetFogQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetEnableKeyboardSprintWalkToggle(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetEffectSoundVolume(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicRange(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetDLSSSharpness(float NewSharpness);
    
    UFUNCTION(BlueprintCallable)
    void SetCursorSpeedMultiplier(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetControllerRumble(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetColorVisionDeficiencyType(EColorVisionDeficiency NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetBrightness(float NewBrightness);
    
    UFUNCTION(BlueprintCallable)
    void SetAudioVisualizer(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetAntiAliasMode(EAntiAliasingMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysUseCameraAiming(bool NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetAltTooltipsEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetAccessibilitySpellToggle(bool ToggleOn);
    
    UFUNCTION(BlueprintCallable)
    void SetAccessibilityAudioCueScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    void SetAccessibilityAudioCueOpacity(float Opacity);
    
    UFUNCTION(BlueprintCallable)
    void ResetUISettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetHDRCalibrationSettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetHardwareBenchmark();
    
    UFUNCTION(BlueprintCallable)
    void ResetGraphicsSettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetGameplaySettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetDisplaySettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetConsoleDisplaySettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetBrightnessSetting();
    
    UFUNCTION(BlueprintCallable)
    void ResetAudioSettings();
    
    UFUNCTION(BlueprintCallable)
    void ResetAccessibilitySettings();
    
    UFUNCTION(BlueprintCallable)
    void RequestTooltipsUpdate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PerformanceModeChangeRequiresReboot(const FString& NewPerformanceMode) const;
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRaytracingRebootPopupButtonPressed(UPopupScreen* PopupScreen, int32 CompletionActionIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUncapFrameRateSupported() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPerformanceModeSwitchingAvailable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNvidiaLatencySupported() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNvidiaFrameGenerationSupported() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNvidiaFrameGenerationLatencyModeCurrentlySupported(ENvidiaLatencyMode InMode) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInRaytracingPerformanceMode() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsHDTextureInstallationAllowed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHardwareBenchmarkApplied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFidelityFXCasEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDLSSEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasHardwareBenchmark() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleFrameRateCapOnPerformanceModeChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVoiceSoundVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseMinimalHud();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetUpscaleSoftness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EUpscaleMode GetUpscaleMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTiltSensitivity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTiltControls();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetSwitchTextLanguage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSubtitlesEnabled();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSteamDeckV1_GPUDeviceID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSoundMuted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSkyQuality() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowXPElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowTutorialElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowToolWheelElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowTargetName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowTargetHighlights();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowTargetElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowSpellElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowSpecialNotificationElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowNotificationElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowMissionElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowMeterElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowMapElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowHudBeacons();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowEnemyDamageElements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowBeastControls();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSelectedMonitor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSelectedGPU(FGraphicsAdapterDesc& OutGpuDesc) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRGBPeripheralsEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRaytracingShadows() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRaytracingReflections() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRaytracingQuality() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetRaytracingAmbientOcclusion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPopulationQuality() const;
    
    UFUNCTION(BlueprintCallable)
    static UPhoenixGameSettings* GetPhoenixGameSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPerformanceMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPauseOnFocusLoss() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FNvidiaLatencyModeInfo> GetNvidiaLatencyPermittedModes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENvidiaLatencyMode GetNvidiaLatencyMode(bool bDoCheck) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNvidiaFrameGeneration(bool bDoCheck) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetNativeResolutionOfCurrentMonitor(int32 OverrideMonitorIdx) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMusicSoundVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMonoAudio();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMiniMapSize();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMiniMapPathEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMiniMapOpacity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMenuReaderVolume() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMenuReaderVoice(FString& OutVoiceID, FString& OutDescription, FString& OutGender) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMenuReaderEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetMasteringSuite();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetINILanguageSetting();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHighContrastMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetHDRToneMapParameters(float& OutMinToneMapLuminance, float& OutMidToneMapLuminance, float& OutMaxToneMapLuminance, float& NewUIBrightness) const;
    
    UFUNCTION(BlueprintCallable)
    static void GetGPUDeviceIDandRev(int32& OutDeviceID, int32& OutDeviceRevision);
    
    UFUNCTION(BlueprintCallable)
    bool GetFrameRateUncapped();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFontSizeOffset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFontIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFogQuality() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnableKeyboardSprintWalkToggle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEffectsSoundVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDynamicRange();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDLSSSharpness() const;
    
    UFUNCTION(BlueprintCallable)
    void GetDifficultyGamePreset(UPARAM(Ref) EDifficulty& Difficulty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAntiAliasingMode GetDefaultAntiAliasMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCursorSpeedMultiplier();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetControllerRumble();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EColorVisionDeficiency GetColorVisionDeficiencyType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBrightness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FString> GetAvailablePerformanceModesForBootFlow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FString> GetAvailablePerformanceModes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAudioVisualizer();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAntiAliasingMode GetAntiAliasMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAlwaysUseCameraAiming();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAltTooltipsEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAccessibilitySpellToggle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAccessibilityAudioCueScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAccessibilityAudioCueOpacity();
    
    UFUNCTION(BlueprintCallable)
    void FinalizeMinimapSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EqualEqual_GraphicsAdapterDesc(const FGraphicsAdapterDesc& A, const FGraphicsAdapterDesc& B);
    
    UFUNCTION(BlueprintCallable)
    void EnableFidelityFXCas(bool bShouldEnable);
    
    UFUNCTION(BlueprintCallable)
    FString CreatePerformanceModesOptionDesc();
    
    UFUNCTION(BlueprintCallable)
    void ClearHighContrastMode(EHighContrastMode inContrastMode);
    
    UFUNCTION(BlueprintCallable)
    bool CanUncapFrameRate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPerformAutoReboot() const;
    
    UFUNCTION(BlueprintCallable)
    void AttemptToApplyPerformanceMode(bool IsGameBootup);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreNonCinematicElementsHidden() const;
    
    UFUNCTION(BlueprintCallable)
    void ApplySettingsDetailed(bool bApplyResolutionSettings, bool bApplyNonResolutionSettings, bool bRequestUIUpdate, bool bSaveSettings, bool bCheckForCommandLineOverrides);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowOptionToSetAlwaysUseCameraAiming();
    
};

