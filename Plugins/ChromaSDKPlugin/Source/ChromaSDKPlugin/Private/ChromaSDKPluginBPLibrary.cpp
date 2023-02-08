#include "ChromaSDKPluginBPLibrary.h"

void UChromaSDKPluginBPLibrary::UsePreloadingName(const FString& AnimationName, bool Flag) {
}

void UChromaSDKPluginBPLibrary::UsePreloading(int32 animationId, bool Flag) {
}

void UChromaSDKPluginBPLibrary::UseIdleAnimations(bool Flag) {
}

void UChromaSDKPluginBPLibrary::UseIdleAnimation(EChromaSDKDeviceEnum::Type device, bool Flag) {
}

void UChromaSDKPluginBPLibrary::UnloadAnimationName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::UnloadAnimation(const int32 animationId) {
}

void UChromaSDKPluginBPLibrary::TrimStartFramesName(const FString& AnimationName, int32 NumberOfFrames) {
}

void UChromaSDKPluginBPLibrary::TrimStartFrames(int32 animationId, int32 NumberOfFrames) {
}

void UChromaSDKPluginBPLibrary::TrimFrameName(const FString& AnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::TrimFrame(int32 animationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::TrimEndFramesName(const FString& AnimationName, int32 lastFrameId) {
}

void UChromaSDKPluginBPLibrary::TrimEndFrames(int32 animationId, int32 lastFrameId) {
}

FLinearColor UChromaSDKPluginBPLibrary::ToLinearColor(int32 colorParam) {
    return FLinearColor{};
}

int32 UChromaSDKPluginBPLibrary::ToBGR(const FLinearColor& colorParam) {
    return 0;
}

bool UChromaSDKPluginBPLibrary::SupportsStreaming() {
    return false;
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::StreamWatchEnd() {
}

void UChromaSDKPluginBPLibrary::StreamWatch(const FString& streamId, int32 Timestamp) {
}

bool UChromaSDKPluginBPLibrary::StreamSetFocus(const FString& streamFocus) {
    return false;
}

bool UChromaSDKPluginBPLibrary::StreamReleaseShortcode(const FString& shortcode) {
    return false;
}

FString UChromaSDKPluginBPLibrary::StreamGetStatusString(const TEnumAsByte<EChromaSDKStreamStatusEnum::Type> Status) {
    return TEXT("");
}

TEnumAsByte<EChromaSDKStreamStatusEnum::Type> UChromaSDKPluginBPLibrary::StreamGetStatus() {
    return EChromaSDKStreamStatusEnum::READY;
}

FString UChromaSDKPluginBPLibrary::StreamGetKey(const FString& shortcode) {
    return TEXT("");
}

FString UChromaSDKPluginBPLibrary::StreamGetId(const FString& shortcode) {
    return TEXT("");
}

FString UChromaSDKPluginBPLibrary::StreamGetFocus() {
    return TEXT("");
}

FString UChromaSDKPluginBPLibrary::StreamGetAuthShortcode(const FString& Platform, const FString& Title) {
    return TEXT("");
}

void UChromaSDKPluginBPLibrary::StreamBroadcastEnd() {
}

void UChromaSDKPluginBPLibrary::StreamBroadcast(const FString& streamId, const FString& streamKey) {
}

void UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::Type device) {
}

void UChromaSDKPluginBPLibrary::StopAnimations(const TArray<FString>& animationNames) {
}

void UChromaSDKPluginBPLibrary::StopAnimationComposite(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::StopAnimation(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::StopAll() {
}

void UChromaSDKPluginBPLibrary::SetStaticColorAll(const FLinearColor& Color) {
}

void UChromaSDKPluginBPLibrary::SetStaticColor(EChromaSDKDeviceEnum::Type device, const FLinearColor& Color) {
}

void UChromaSDKPluginBPLibrary::SetMouseLedColor(EChromaSDKMouseLed::Type led, const FLinearColor& colorParam, TArray<FChromaSDKColors>& Colors) {
}

void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorName(const FString& AnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorAllFramesName(const FString& AnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorAllFrames(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysNonZeroColor(int32 animationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorRGBName(const FString& AnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorRGB(int32 animationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorName(const FString& AnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesRGBName(const FString& AnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesRGB(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(const FString& AnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysColorAllFrames(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeysColor(int32 animationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyRowColumnColorName(const FString& AnimationName, const int32 FrameIndex, const int32 Row, const int32 Column, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorName(const FString& AnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorAllFramesName(const FString& AnimationName, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorAllFrames(int32 animationId, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyNonZeroColor(int32 animationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyColorName(const FString& AnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyColorAllFramesName(const FString& AnimationName, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyColorAllFrames(int32 animationId, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyColor(int32 animationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::SetKeyboardKeyColor(EChromaSDKKeyboardKey::Type Key, const FLinearColor& colorParam, TArray<FChromaSDKColors>& Colors) {
}

void UChromaSDKPluginBPLibrary::SetIdleAnimationName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::SetCurrentFrameName(const FString& AnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::SetCurrentFrame(int32 animationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::SetChromaCustomFlagName(const FString& AnimationName, bool Flag) {
}

void UChromaSDKPluginBPLibrary::SetChromaCustomColorAllFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::ReverseAllFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::ReverseAllFrames(int32 animationId) {
}

void UChromaSDKPluginBPLibrary::ReduceFramesName(const FString& AnimationName, int32 N) {
}

void UChromaSDKPluginBPLibrary::ReduceFrames(int32 animationId, int32 N) {
}

void UChromaSDKPluginBPLibrary::PreviewFrameName(const FString& AnimationName, int32 frameId) {
}

int32 UChromaSDKPluginBPLibrary::PreviewFrame(int32 animationId, int32 frameId) {
    return 0;
}

void UChromaSDKPluginBPLibrary::PlayAnimations(const TArray<FString>& animationNames, bool Loop) {
}

void UChromaSDKPluginBPLibrary::PlayAnimationName(const FString& AnimationName, bool Loop) {
}

void UChromaSDKPluginBPLibrary::PlayAnimationComposite(const FString& AnimationName, bool Loop) {
}

void UChromaSDKPluginBPLibrary::PlayAnimation(const FString& AnimationName, bool Loop) {
}

void UChromaSDKPluginBPLibrary::OverrideFrameDurationName(const FString& AnimationName, float Duration) {
}

void UChromaSDKPluginBPLibrary::OpenAnimationFromMemory(const TArray<uint8>& Data, const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFrames(int32 animationId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetNonZeroColors(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetColorsName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetColorsAllFramesName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetColorsAllFrames(int32 animationId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::OffsetColors(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MultiplyTargetColorLerpAllFramesName(const FString& AnimationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2) {
}

void UChromaSDKPluginBPLibrary::MultiplyTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2) {
}

void UChromaSDKPluginBPLibrary::MultiplyNonZeroTargetColorLerpAllFramesName(const FString& AnimationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2) {
}

void UChromaSDKPluginBPLibrary::MultiplyNonZeroTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityName(const FString& AnimationName, int32 frameId, float Intensity) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityColorAllFrames(int32 animationId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityColor(int32 animationId, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(const FString& AnimationName, float Intensity) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFrames(int32 animationId, float Intensity) {
}

void UChromaSDKPluginBPLibrary::MultiplyIntensity(int32 animationId, int32 frameId, float Intensity) {
}

void UChromaSDKPluginBPLibrary::MultiplyColorLerpAllFramesName(const FString& AnimationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2) {
}

void UChromaSDKPluginBPLibrary::MultiplyColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRGBName(const FString& AnimationName, int32 frameCount, float Duration, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRGB(int32 animationId, int32 frameCount, float Duration, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomName(const FString& AnimationName, int32 frameCount, float Duration) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomBlackAndWhiteName(const FString& AnimationName, int32 frameCount, float Duration) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomBlackAndWhite(int32 animationId, int32 frameCount, float Duration) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandom(int32 animationId, int32 frameCount, float Duration) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesName(const FString& AnimationName, int32 frameCount, float Duration, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::MakeBlankFrames(int32 animationId, int32 frameCount, float Duration, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::LoadAnimationName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::LoadAnimation(const int32 animationId) {
}

int32 UChromaSDKPluginBPLibrary::LerpColorBGR(int32 From, int32 To, float T) {
    return 0;
}

FLinearColor UChromaSDKPluginBPLibrary::LerpColor(FLinearColor colorParam1, FLinearColor colorParam2, float T) {
    return FLinearColor{};
}

float UChromaSDKPluginBPLibrary::Lerp(float Start, float End, float amt) {
    return 0.0f;
}

bool UChromaSDKPluginBPLibrary::IsPlatformWindows() {
    return false;
}

bool UChromaSDKPluginBPLibrary::IsInitialized() {
    return false;
}

bool UChromaSDKPluginBPLibrary::IsAnimationTypePlaying(TEnumAsByte<EChromaSDKDeviceEnum::Type> device) {
    return false;
}

bool UChromaSDKPluginBPLibrary::IsAnimationPlaying(const FString& AnimationName) {
    return false;
}

void UChromaSDKPluginBPLibrary::InvertColorsAllFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::InvertColorsAllFrames(int32 animationId) {
}

void UChromaSDKPluginBPLibrary::InsertFrameName(const FString& AnimationName, int32 sourceFrame, int32 targetFrame) {
}

void UChromaSDKPluginBPLibrary::InsertFrame(int32 animationId, int32 sourceFrame, int32 targetFrame) {
}

void UChromaSDKPluginBPLibrary::InsertDelayName(const FString& AnimationName, int32 frameId, int32 Delay) {
}

void UChromaSDKPluginBPLibrary::InsertDelay(int32 animationId, int32 frameId, int32 Delay) {
}

FLinearColor UChromaSDKPluginBPLibrary::GetRGB(int32 Red, int32 Green, int32 Blue) {
    return FLinearColor{};
}

int32 UChromaSDKPluginBPLibrary::GetPlayingAnimationId(int32 Index) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetPlayingAnimationCount() {
    return 0;
}

FLinearColor UChromaSDKPluginBPLibrary::GetMouseLedColor(TEnumAsByte<EChromaSDKMouseLed::Type> led, TArray<FChromaSDKColors>& Colors) {
    return FLinearColor{};
}

int32 UChromaSDKPluginBPLibrary::GetMaxRow(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetMaxLeds(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetMaxColumn(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device) {
    return 0;
}

FLinearColor UChromaSDKPluginBPLibrary::GetKeyColorName(const FString& AnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
    return FLinearColor{};
}

FLinearColor UChromaSDKPluginBPLibrary::GetKeyColor(int32 animationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
    return FLinearColor{};
}

int32 UChromaSDKPluginBPLibrary::GetKeyboardRzKey(TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
    return 0;
}

TEnumAsByte<EChromaSDKKeyboardKey::Type> UChromaSDKPluginBPLibrary::GetKeyboardRazerKey(FKey Key) {
    return EChromaSDKKeyboardKey::KK_ESC;
}

FLinearColor UChromaSDKPluginBPLibrary::GetKeyboardKeyColor(TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, TArray<FChromaSDKColors>& Colors) {
    return FLinearColor{};
}

int32 UChromaSDKPluginBPLibrary::GetFrameCountName(const FString& AnimationName) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetFrameCount(const int32 animationId) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetCurrentFrameName(const FString& AnimationName) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetCurrentFrame(int32 animationId) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetBGRInt(int32 Red, int32 Green, int32 Blue) {
    return 0;
}

FString UChromaSDKPluginBPLibrary::GetAnimationName(const int32 animationId) {
    return TEXT("");
}

int32 UChromaSDKPluginBPLibrary::GetAnimationIdByIndex(int32 Index) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetAnimationId(const FString& AnimationName) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetAnimationCount() {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::GetAnimation(const FString& AnimationName) {
    return 0;
}

void UChromaSDKPluginBPLibrary::FillZeroColorRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillZeroColorRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillZeroColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFrames(int32 animationId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillZeroColor(int32 animationId, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillThresholdRGBColorsAllFramesRGBName(const FString& AnimationName, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdRGBColorsAllFramesRGB(int32 animationId, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsRGBName(const FString& AnimationName, int32 frameId, int32 Threshold, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsRGB(int32 animationId, int32 frameId, int32 Threshold, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsMinMaxAllFramesRGBName(const FString& AnimationName, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsMinMaxAllFramesRGB(int32 animationId, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesRGBName(const FString& AnimationName, int32 Threshold, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesRGB(int32 animationId, int32 Threshold, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesName(const FString& AnimationName, int32 Threshold, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFrames(int32 animationId, int32 Threshold, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsName(const FString& AnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteName(const FString& AnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteAllFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteAllFrames(int32 animationId) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhite(int32 animationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsAllFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::FillRandomColorsAllFrames(int32 animationId) {
}

void UChromaSDKPluginBPLibrary::FillRandomColors(int32 animationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFrames(int32 animationId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillNonZeroColor(int32 animationId, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillColorRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillColorRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillColorAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillColorAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue) {
}

void UChromaSDKPluginBPLibrary::FillColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillColorAllFrames(int32 animationId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FillColor(int32 animationId, int32 frameId, const FLinearColor& colorParam) {
}

void UChromaSDKPluginBPLibrary::FadeStartFramesName(const FString& AnimationName, int32 fade) {
}

void UChromaSDKPluginBPLibrary::FadeStartFrames(int32 animationId, int32 fade) {
}

void UChromaSDKPluginBPLibrary::FadeEndFramesName(const FString& AnimationName, int32 fade) {
}

void UChromaSDKPluginBPLibrary::FadeEndFrames(int32 animationId, int32 fade) {
}

void UChromaSDKPluginBPLibrary::DuplicateMirrorFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::DuplicateMirrorFrames(int32 animationId) {
}

void UChromaSDKPluginBPLibrary::DuplicateFramesName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::DuplicateFrames(int32 animationId) {
}

void UChromaSDKPluginBPLibrary::DuplicateFirstFrameName(const FString& AnimationName, int32 frameCount) {
}

void UChromaSDKPluginBPLibrary::DuplicateFirstFrame(int32 animationId, int32 frameCount) {
}

TArray<FChromaSDKColors> UChromaSDKPluginBPLibrary::CreateRandomColorsBlackAndWhite2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device) {
    return TArray<FChromaSDKColors>();
}

TArray<FLinearColor> UChromaSDKPluginBPLibrary::CreateRandomColorsBlackAndWhite1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device) {
    return TArray<FLinearColor>();
}

TArray<FChromaSDKColors> UChromaSDKPluginBPLibrary::CreateRandomColors2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device) {
    return TArray<FChromaSDKColors>();
}

TArray<FLinearColor> UChromaSDKPluginBPLibrary::CreateRandomColors1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device) {
    return TArray<FLinearColor>();
}

TArray<FChromaSDKColors> UChromaSDKPluginBPLibrary::CreateColors2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device) {
    return TArray<FChromaSDKColors>();
}

TArray<FLinearColor> UChromaSDKPluginBPLibrary::CreateColors1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device) {
    return TArray<FLinearColor>();
}

void UChromaSDKPluginBPLibrary::CopyZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::CopyZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColorAllFrames(int32 sourceAnimationId, int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeyColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::CopyKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyKeysColorAllFrames(int32 sourceAnimationId, int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyKeysColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys) {
}

void UChromaSDKPluginBPLibrary::CopyKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
}

void UChromaSDKPluginBPLibrary::CopyKeyColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key) {
}

void UChromaSDKPluginBPLibrary::CopyAnimationName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::CopyAnimation(int32 sourceAnimationId, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::CopyAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::CopyAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::CopyAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::CopyAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::CloseAnimationName(const FString& AnimationName) {
}

void UChromaSDKPluginBPLibrary::CloseAnimation(const int32 animationId) {
}

void UChromaSDKPluginBPLibrary::CloseAll() {
}

void UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::Type device) {
}

void UChromaSDKPluginBPLibrary::ClearAll() {
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKUnInit() {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(const FChromaSDKGuid& EffectId) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKInitSDK(const FChromaSDKAppInfoType& appInfo) {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKInit() {
    return 0;
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(const FChromaSDKGuid& EffectId) {
    return 0;
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(TEnumAsByte<EChromaSDKDeviceEnum::Type> device, const FLinearColor& colorParam) {
    return FChromaSDKEffectResult{};
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectNone(TEnumAsByte<EChromaSDKDeviceEnum::Type> device) {
    return FChromaSDKEffectResult{};
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectKeyboardCustom2D(const TArray<FChromaSDKColors>& Colors) {
    return FChromaSDKEffectResult{};
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device, const TArray<FChromaSDKColors>& Colors) {
    return FChromaSDKEffectResult{};
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device, const TArray<FLinearColor>& Colors) {
    return FChromaSDKEffectResult{};
}

void UChromaSDKPluginBPLibrary::AppendAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::AppendAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId) {
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId) {
}

UChromaSDKPluginBPLibrary::UChromaSDKPluginBPLibrary() {
}

