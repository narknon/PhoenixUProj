#include "PhoenixGameSettings.h"

class UObject;
class UPhoenixGameSettings;
class UPopupScreen;

void UPhoenixGameSettings::TriggerAutoReboot() const {
}

bool UPhoenixGameSettings::TestHighContrastMode(EHighContrastMode inContrastMode) {
    return false;
}

UPopupScreen* UPhoenixGameSettings::ShowRaytracingRebootPopup() {
    return NULL;
}

bool UPhoenixGameSettings::ShouldShowRGBPeripheralsButton() {
    return false;
}

bool UPhoenixGameSettings::ShouldControllerRumble() {
    return false;
}

void UPhoenixGameSettings::SetVoiceSoundVolume(float NewVal) {
}

void UPhoenixGameSettings::SetUseMinimalHud(bool NewVal) {
}

void UPhoenixGameSettings::SetUpscaleSoftness(float NewSharpness) {
}

void UPhoenixGameSettings::SetUpscaleMode(EUpscaleMode UpscaleModeInput) {
}

void UPhoenixGameSettings::SetUncapFrameRate(bool InUncapFrameRate) {
}

void UPhoenixGameSettings::SetTiltSensitivity(float NewVal) {
}

void UPhoenixGameSettings::SetTiltControls(bool NewVal) {
}

void UPhoenixGameSettings::SetSwitchTextLanguage(const FString& Lang) {
}

void UPhoenixGameSettings::SetSubtitlesEnabled(bool NewVal) {
}

void UPhoenixGameSettings::SetSoundMuted(bool NewVal) {
}

void UPhoenixGameSettings::SetSkyQuality(int32 Value) {
}

void UPhoenixGameSettings::SetShowXPElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowTutorialElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowToolWheelElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowTargetName(bool NewVal) {
}

void UPhoenixGameSettings::SetShowTargetHighlights(bool NewVal) {
}

void UPhoenixGameSettings::SetShowTargetElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowSpellElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowSpecialNotificationElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowNotificationElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowMissionElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowMeterElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowMapElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowHudBeacons(bool NewVal) {
}

void UPhoenixGameSettings::SetShowEnemyDamageElements(bool NewVal) {
}

void UPhoenixGameSettings::SetShowBeastControls(bool NewVal) {
}

bool UPhoenixGameSettings::SetSelectedMonitor(int32 SelectedMonitorIdx, bool bForceFullscreen) {
    return false;
}

void UPhoenixGameSettings::SetSelectedGPU(const FGraphicsAdapterDesc& GpuDesc) {
}

void UPhoenixGameSettings::SetRGBPeripheralsEnabled(bool NewVal) {
}

void UPhoenixGameSettings::SetRaytracingSupported(const bool bShouldSupport) const {
}

void UPhoenixGameSettings::SetRaytracingShadows(bool bInEnableRaytracingShadows) {
}

void UPhoenixGameSettings::SetRaytracingReflections(bool bInEnableRaytracingReflections) {
}

void UPhoenixGameSettings::SetRaytracingQuality(int32 Value) {
}

void UPhoenixGameSettings::SetRaytracingAmbientOcclusion(bool bInEnableRaytracingAO) {
}

void UPhoenixGameSettings::SetPopulationQuality(int32 Value) {
}

void UPhoenixGameSettings::SetPerformanceMode(const FString& InPerformanceMode) {
}

void UPhoenixGameSettings::SetPauseOnFocusLoss(bool bEnable) {
}

void UPhoenixGameSettings::SetNvidiaLatencyMode(ENvidiaLatencyMode InMode) {
}

void UPhoenixGameSettings::SetNvidiaFrameGeneration(bool bEnabled) {
}

void UPhoenixGameSettings::SetMusicSoundVolume(float NewVal) {
}

void UPhoenixGameSettings::SetMonoAudio(bool NewVal) {
}

void UPhoenixGameSettings::SetMiniMapSize(int32 Size) {
}

void UPhoenixGameSettings::SetMiniMapPathEnabled(bool Enabled) {
}

void UPhoenixGameSettings::SetMiniMapOpacity(float Opacity) {
}

void UPhoenixGameSettings::SetMenuReaderVolume(float InVolume) {
}

void UPhoenixGameSettings::SetMenuReaderVoice(const FString& InVoiceID, const FString& InDescription, const FString& InGender) {
}

void UPhoenixGameSettings::SetMenuReaderEnabled(bool Enabled) {
}

void UPhoenixGameSettings::SetMasteringSuite(const FString& NewVal) {
}

void UPhoenixGameSettings::SetINILanguageSetting(const FString& NewVal) {
}

void UPhoenixGameSettings::SetIgnoreConfirmVideoMode(const bool bIgnore) {
}

void UPhoenixGameSettings::SetHighContrastModeBits(int32 inContrastMode) {
}

void UPhoenixGameSettings::SetHighContrastMode(EHighContrastMode inContrastMode) {
}

void UPhoenixGameSettings::SetHideNonCinematicElements(bool bHide, const UObject* InInstigator) {
}

bool UPhoenixGameSettings::SetHDRToneMapParameters(bool bAutomatic, float NewMinToneMapLuminance, float NewMidToneMapLuminance, float NewMaxToneMapLuminance, float NewUIBrightness) {
    return false;
}

void UPhoenixGameSettings::SetFontSizeOffset(int32 NewVal) {
}

void UPhoenixGameSettings::SetFontIndex(int32 NewVal) {
}

void UPhoenixGameSettings::SetFogQuality(int32 Value) {
}

void UPhoenixGameSettings::SetEnableKeyboardSprintWalkToggle(bool NewVal) {
}

void UPhoenixGameSettings::SetEffectSoundVolume(float NewVal) {
}

void UPhoenixGameSettings::SetDynamicRange(float NewVal) {
}

void UPhoenixGameSettings::SetDLSSSharpness(float NewSharpness) {
}

void UPhoenixGameSettings::SetCursorSpeedMultiplier(float NewVal) {
}

void UPhoenixGameSettings::SetControllerRumble(bool NewVal) {
}

void UPhoenixGameSettings::SetColorVisionDeficiencyType(EColorVisionDeficiency NewVal) {
}

void UPhoenixGameSettings::SetBrightness(float NewBrightness) {
}

void UPhoenixGameSettings::SetAudioVisualizer(bool NewVal) {
}

void UPhoenixGameSettings::SetAntiAliasMode(EAntiAliasingMode Mode) {
}

void UPhoenixGameSettings::SetAlwaysUseCameraAiming(bool NewVal) {
}

void UPhoenixGameSettings::SetAltTooltipsEnabled(bool bEnable) {
}

void UPhoenixGameSettings::SetAccessibilitySpellToggle(bool ToggleOn) {
}

void UPhoenixGameSettings::SetAccessibilityAudioCueScale(float Scale) {
}

void UPhoenixGameSettings::SetAccessibilityAudioCueOpacity(float Opacity) {
}

void UPhoenixGameSettings::ResetUISettings() {
}

void UPhoenixGameSettings::ResetHDRCalibrationSettings() {
}

void UPhoenixGameSettings::ResetHardwareBenchmark() {
}

void UPhoenixGameSettings::ResetGraphicsSettings() {
}

void UPhoenixGameSettings::ResetGameplaySettings() {
}

void UPhoenixGameSettings::ResetDisplaySettings() {
}

void UPhoenixGameSettings::ResetConsoleDisplaySettings() {
}

void UPhoenixGameSettings::ResetBrightnessSetting() {
}

void UPhoenixGameSettings::ResetAudioSettings() {
}

void UPhoenixGameSettings::ResetAccessibilitySettings() {
}

void UPhoenixGameSettings::RequestTooltipsUpdate() {
}

bool UPhoenixGameSettings::PerformanceModeChangeRequiresReboot(const FString& NewPerformanceMode) const {
    return false;
}

void UPhoenixGameSettings::OnRaytracingRebootPopupButtonPressed(UPopupScreen* PopupScreen, int32 CompletionActionIndex) {
}

bool UPhoenixGameSettings::IsUncapFrameRateSupported() const {
    return false;
}

bool UPhoenixGameSettings::IsPerformanceModeSwitchingAvailable() const {
    return false;
}

bool UPhoenixGameSettings::IsNvidiaLatencySupported() const {
    return false;
}

bool UPhoenixGameSettings::IsNvidiaFrameGenerationSupported() const {
    return false;
}

bool UPhoenixGameSettings::IsNvidiaFrameGenerationLatencyModeCurrentlySupported(ENvidiaLatencyMode InMode) const {
    return false;
}

bool UPhoenixGameSettings::IsInRaytracingPerformanceMode() const {
    return false;
}

bool UPhoenixGameSettings::IsHDTextureInstallationAllowed() {
    return false;
}

bool UPhoenixGameSettings::IsHardwareBenchmarkApplied() const {
    return false;
}

bool UPhoenixGameSettings::IsFidelityFXCasEnabled() const {
    return false;
}

bool UPhoenixGameSettings::IsDLSSEnabled() const {
    return false;
}

bool UPhoenixGameSettings::HasHardwareBenchmark() const {
    return false;
}

void UPhoenixGameSettings::HandleFrameRateCapOnPerformanceModeChanged() {
}

float UPhoenixGameSettings::GetVoiceSoundVolume() {
    return 0.0f;
}

bool UPhoenixGameSettings::GetUseMinimalHud() {
    return false;
}

float UPhoenixGameSettings::GetUpscaleSoftness() const {
    return 0.0f;
}

EUpscaleMode UPhoenixGameSettings::GetUpscaleMode() const {
    return EUpscaleMode::None;
}

float UPhoenixGameSettings::GetTiltSensitivity() {
    return 0.0f;
}

bool UPhoenixGameSettings::GetTiltControls() {
    return false;
}

FString UPhoenixGameSettings::GetSwitchTextLanguage() {
    return TEXT("");
}

bool UPhoenixGameSettings::GetSubtitlesEnabled() {
    return false;
}

int32 UPhoenixGameSettings::GetSteamDeckV1_GPUDeviceID() {
    return 0;
}

bool UPhoenixGameSettings::GetSoundMuted() {
    return false;
}

int32 UPhoenixGameSettings::GetSkyQuality() const {
    return 0;
}

bool UPhoenixGameSettings::GetShowXPElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowTutorialElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowToolWheelElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowTargetName() {
    return false;
}

bool UPhoenixGameSettings::GetShowTargetHighlights() {
    return false;
}

bool UPhoenixGameSettings::GetShowTargetElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowSpellElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowSpecialNotificationElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowNotificationElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowMissionElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowMeterElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowMapElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowHudBeacons() {
    return false;
}

bool UPhoenixGameSettings::GetShowEnemyDamageElements() {
    return false;
}

bool UPhoenixGameSettings::GetShowBeastControls() {
    return false;
}

int32 UPhoenixGameSettings::GetSelectedMonitor() const {
    return 0;
}

bool UPhoenixGameSettings::GetSelectedGPU(FGraphicsAdapterDesc& OutGpuDesc) const {
    return false;
}

bool UPhoenixGameSettings::GetRGBPeripheralsEnabled() {
    return false;
}

bool UPhoenixGameSettings::GetRaytracingShadows() const {
    return false;
}

bool UPhoenixGameSettings::GetRaytracingReflections() const {
    return false;
}

int32 UPhoenixGameSettings::GetRaytracingQuality() const {
    return 0;
}

bool UPhoenixGameSettings::GetRaytracingAmbientOcclusion() const {
    return false;
}

int32 UPhoenixGameSettings::GetPopulationQuality() const {
    return 0;
}

UPhoenixGameSettings* UPhoenixGameSettings::GetPhoenixGameSettings() {
    return NULL;
}

FString UPhoenixGameSettings::GetPerformanceMode() const {
    return TEXT("");
}

bool UPhoenixGameSettings::GetPauseOnFocusLoss() const {
    return false;
}

TArray<FNvidiaLatencyModeInfo> UPhoenixGameSettings::GetNvidiaLatencyPermittedModes() const {
    return TArray<FNvidiaLatencyModeInfo>();
}

ENvidiaLatencyMode UPhoenixGameSettings::GetNvidiaLatencyMode(bool bDoCheck) const {
    return ENvidiaLatencyMode::Off;
}

bool UPhoenixGameSettings::GetNvidiaFrameGeneration(bool bDoCheck) const {
    return false;
}

FIntPoint UPhoenixGameSettings::GetNativeResolutionOfCurrentMonitor(int32 OverrideMonitorIdx) const {
    return FIntPoint{};
}

float UPhoenixGameSettings::GetMusicSoundVolume() {
    return 0.0f;
}

bool UPhoenixGameSettings::GetMonoAudio() {
    return false;
}

int32 UPhoenixGameSettings::GetMiniMapSize() {
    return 0;
}

bool UPhoenixGameSettings::GetMiniMapPathEnabled() {
    return false;
}

float UPhoenixGameSettings::GetMiniMapOpacity() {
    return 0.0f;
}

float UPhoenixGameSettings::GetMenuReaderVolume() const {
    return 0.0f;
}

void UPhoenixGameSettings::GetMenuReaderVoice(FString& OutVoiceID, FString& OutDescription, FString& OutGender) const {
}

bool UPhoenixGameSettings::GetMenuReaderEnabled() const {
    return false;
}

FString UPhoenixGameSettings::GetMasteringSuite() {
    return TEXT("");
}

FString UPhoenixGameSettings::GetINILanguageSetting() {
    return TEXT("");
}

int32 UPhoenixGameSettings::GetHighContrastMode() {
    return 0;
}

void UPhoenixGameSettings::GetHDRToneMapParameters(float& OutMinToneMapLuminance, float& OutMidToneMapLuminance, float& OutMaxToneMapLuminance, float& NewUIBrightness) const {
}

void UPhoenixGameSettings::GetGPUDeviceIDandRev(int32& OutDeviceID, int32& OutDeviceRevision) {
}

bool UPhoenixGameSettings::GetFrameRateUncapped() {
    return false;
}

int32 UPhoenixGameSettings::GetFontSizeOffset() {
    return 0;
}

int32 UPhoenixGameSettings::GetFontIndex() {
    return 0;
}

int32 UPhoenixGameSettings::GetFogQuality() const {
    return 0;
}

bool UPhoenixGameSettings::GetEnableKeyboardSprintWalkToggle() {
    return false;
}

float UPhoenixGameSettings::GetEffectsSoundVolume() {
    return 0.0f;
}

float UPhoenixGameSettings::GetDynamicRange() {
    return 0.0f;
}

float UPhoenixGameSettings::GetDLSSSharpness() const {
    return 0.0f;
}

void UPhoenixGameSettings::GetDifficultyGamePreset(EDifficulty& Difficulty) {
}

EAntiAliasingMode UPhoenixGameSettings::GetDefaultAntiAliasMode() const {
    return EAntiAliasingMode::TAA_Low;
}

float UPhoenixGameSettings::GetCursorSpeedMultiplier() {
    return 0.0f;
}

bool UPhoenixGameSettings::GetControllerRumble() {
    return false;
}

EColorVisionDeficiency UPhoenixGameSettings::GetColorVisionDeficiencyType() {
    return EColorVisionDeficiency::NormalVision;
}

float UPhoenixGameSettings::GetBrightness() const {
    return 0.0f;
}

TArray<FString> UPhoenixGameSettings::GetAvailablePerformanceModesForBootFlow() const {
    return TArray<FString>();
}

TArray<FString> UPhoenixGameSettings::GetAvailablePerformanceModes() const {
    return TArray<FString>();
}

bool UPhoenixGameSettings::GetAudioVisualizer() {
    return false;
}

EAntiAliasingMode UPhoenixGameSettings::GetAntiAliasMode() const {
    return EAntiAliasingMode::TAA_Low;
}

bool UPhoenixGameSettings::GetAlwaysUseCameraAiming() {
    return false;
}

bool UPhoenixGameSettings::GetAltTooltipsEnabled() const {
    return false;
}

bool UPhoenixGameSettings::GetAccessibilitySpellToggle() {
    return false;
}

float UPhoenixGameSettings::GetAccessibilityAudioCueScale() {
    return 0.0f;
}

float UPhoenixGameSettings::GetAccessibilityAudioCueOpacity() {
    return 0.0f;
}

void UPhoenixGameSettings::FinalizeMinimapSettings() {
}

bool UPhoenixGameSettings::EqualEqual_GraphicsAdapterDesc(const FGraphicsAdapterDesc& A, const FGraphicsAdapterDesc& B) {
    return false;
}

void UPhoenixGameSettings::EnableFidelityFXCas(bool bShouldEnable) {
}

FString UPhoenixGameSettings::CreatePerformanceModesOptionDesc() {
    return TEXT("");
}

void UPhoenixGameSettings::ClearHighContrastMode(EHighContrastMode inContrastMode) {
}

bool UPhoenixGameSettings::CanUncapFrameRate() {
    return false;
}

bool UPhoenixGameSettings::CanPerformAutoReboot() const {
    return false;
}

void UPhoenixGameSettings::AttemptToApplyPerformanceMode(bool IsGameBootup) {
}

bool UPhoenixGameSettings::AreNonCinematicElementsHidden() const {
    return false;
}

void UPhoenixGameSettings::ApplySettingsDetailed(bool bApplyResolutionSettings, bool bApplyNonResolutionSettings, bool bRequestUIUpdate, bool bSaveSettings, bool bCheckForCommandLineOverrides) {
}

bool UPhoenixGameSettings::AllowOptionToSetAlwaysUseCameraAiming() {
    return false;
}

UPhoenixGameSettings::UPhoenixGameSettings() {
    this->EffectsSoundVolume = 1.00f;
    this->MusicSoundVolume = 1.00f;
    this->VoiceSoundVolume = 1.00f;
    this->SoundMuted = false;
    this->MonoAudio = false;
    this->DynamicRange = 10.00f;
    this->MasteringSuite = TEXT("HomeCinema");
    this->bEnableRaytracingShadows = false;
    this->bEnableRaytracingReflections = false;
    this->bEnableRaytracingAO = false;
    this->bFrameRateUncapped = false;
    this->MenuReaderEnabled = false;
    this->MenuReaderVolume = 0.70f;
    this->ColorVisionDeficiencyType = EColorVisionDeficiency::NormalVision;
    this->CursorSpeedMultiplier = 1.00f;
    this->MiniMapSize = 2;
    this->MiniMapOpacity = 0.65f;
    this->PathLineEnabled = true;
    this->AccessibilityAudioCueOpacity = 0.00f;
    this->AccessibilityAudioCueScale = 0.50f;
    this->UseMinimalHud = false;
    this->ShowTargetHighlights = true;
    this->ShowTargetName = true;
    this->ShowHudBeacons = true;
    this->ShowNotificationElements = true;
    this->ShowXPElements = true;
    this->ShowMissionElements = true;
    this->ShowSpellElements = true;
    this->ShowMeterElements = true;
    this->ShowMapElements = true;
    this->ShowTargetElements = true;
    this->ShowSpecialNotificationElements = true;
    this->ShowTutorialElements = true;
    this->ShowToolWheelElements = true;
    this->ShowEnemyDamageElements = true;
    this->ShowBeastControls = true;
    this->FontSizeOffset = 0;
    this->FontIndex = 0;
    this->HighContrastMode = 0;
    this->AudioVisualizer = false;
    this->bEnableKeyboardSprintWalkToggle = true;
    this->bAccessibilitySpellToggle = false;
    this->SubtitlesEnabled = true;
    this->ControllerRumble = true;
    this->RGBPeripheralsEnabled = true;
    this->AlwaysUseCameraAiming = true;
    this->INILanguageSetting = TEXT("None");
    this->SwitchTextLanguageSetting = TEXT("None");
    this->TiltControls = false;
    this->TiltSensitivity = 1.00f;
    this->bIsUpscaleModeModified = false;
    this->UpscaleMode = EUpscaleMode::DLSS_Quality;
    this->UpscaleSoftness = 0.00f;
    this->AntiAliasingMode = EAntiAliasingMode::TAA_High;
    this->DefaultAntiAliasingMode = EAntiAliasingMode::TAA_High;
    this->NvidiaLatencyMode = ENvidiaLatencyMode::LowLatency;
    this->NvidiaFrameGeneration = true;
    this->Brightness = 2.20f;
    this->MinToneMapLuminance = 0.00f;
    this->MidToneMapLuminance = 25.00f;
    this->MaxToneMapLuminance = 2000.00f;
    this->UIBrightness = 1.00f;
    this->bAutomaticHDRCalibration = true;
    this->MonitorIdx = 0;
    this->bHardwareBenchmarkApplied = false;
    this->GPUConfigPreset = 3;
    this->RecViewDistanceQuality = 3;
    this->RecAntiAliasingQuality = 3;
    this->RecShadowQuality = 3;
    this->RecPostProcessQuality = 3;
    this->RecTextureQuality = 3;
    this->RecEffectsQuality = 3;
    this->RecFoliageQuality = 3;
    this->RecShadingQuality = 3;
    this->RecFogQuality = 3;
    this->RecSkyQuality = 3;
    this->RecPopulationQuality = 3;
    this->RecRaytracingQuality = 3;
    this->bAltTooltipsEnabled = false;
    this->bPauseOnFocusLoss = true;
    this->FrameRateLimitMinimized = 6.00f;
    this->SubVersion = 1;
}

