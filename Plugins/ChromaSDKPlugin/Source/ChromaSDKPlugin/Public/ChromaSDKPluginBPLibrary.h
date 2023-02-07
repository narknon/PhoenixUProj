#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "ChromaSDKAppInfoType.h"
#include "ChromaSDKColors.h"
#include "ChromaSDKEffectResult.h"
#include "ChromaSDKGuid.h"
#include "EChromaSDKDevice1DEnum.h"
#include "EChromaSDKDevice2DEnum.h"
#include "EChromaSDKDeviceEnum.h"
#include "EChromaSDKKeyboardKey.h"
#include "EChromaSDKMouseLed.h"
#include "EChromaSDKStreamStatusEnum.h"
#include "ChromaSDKPluginBPLibrary.generated.h"

UCLASS(Blueprintable)
class CHROMASDKPLUGIN_API UChromaSDKPluginBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UChromaSDKPluginBPLibrary();
    UFUNCTION(BlueprintCallable)
    static void UsePreloadingName(const FString& AnimationName, bool Flag);
    
    UFUNCTION(BlueprintCallable)
    static void UsePreloading(int32 animationId, bool Flag);
    
    UFUNCTION(BlueprintCallable)
    static void UseIdleAnimations(bool Flag);
    
    UFUNCTION(BlueprintCallable)
    static void UseIdleAnimation(EChromaSDKDeviceEnum::Type device, bool Flag);
    
    UFUNCTION(BlueprintCallable)
    static void UnloadAnimationName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void UnloadAnimation(const int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void TrimStartFramesName(const FString& AnimationName, int32 NumberOfFrames);
    
    UFUNCTION(BlueprintCallable)
    static void TrimStartFrames(int32 animationId, int32 NumberOfFrames);
    
    UFUNCTION(BlueprintCallable)
    static void TrimFrameName(const FString& AnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void TrimFrame(int32 animationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void TrimEndFramesName(const FString& AnimationName, int32 lastFrameId);
    
    UFUNCTION(BlueprintCallable)
    static void TrimEndFrames(int32 animationId, int32 lastFrameId);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor ToLinearColor(int32 colorParam);
    
    UFUNCTION(BlueprintCallable)
    static int32 ToBGR(const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static bool SupportsStreaming();
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void SubtractNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void StreamWatchEnd();
    
    UFUNCTION(BlueprintCallable)
    static void StreamWatch(const FString& streamId, int32 Timestamp);
    
    UFUNCTION(BlueprintCallable)
    static bool StreamSetFocus(const FString& streamFocus);
    
    UFUNCTION(BlueprintCallable)
    static bool StreamReleaseShortcode(const FString& shortcode);
    
    UFUNCTION(BlueprintCallable)
    static FString StreamGetStatusString(const TEnumAsByte<EChromaSDKStreamStatusEnum::Type> Status);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EChromaSDKStreamStatusEnum::Type> StreamGetStatus();
    
    UFUNCTION(BlueprintCallable)
    static FString StreamGetKey(const FString& shortcode);
    
    UFUNCTION(BlueprintCallable)
    static FString StreamGetId(const FString& shortcode);
    
    UFUNCTION(BlueprintCallable)
    static FString StreamGetFocus();
    
    UFUNCTION(BlueprintCallable)
    static FString StreamGetAuthShortcode(const FString& Platform, const FString& Title);
    
    UFUNCTION(BlueprintCallable)
    static void StreamBroadcastEnd();
    
    UFUNCTION(BlueprintCallable)
    static void StreamBroadcast(const FString& streamId, const FString& streamKey);
    
    UFUNCTION(BlueprintCallable)
    static void StopAnimationType(EChromaSDKDeviceEnum::Type device);
    
    UFUNCTION(BlueprintCallable)
    static void StopAnimations(const TArray<FString>& animationNames);
    
    UFUNCTION(BlueprintCallable)
    static void StopAnimationComposite(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void StopAnimation(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void StopAll();
    
    UFUNCTION(BlueprintCallable)
    static void SetStaticColorAll(const FLinearColor& Color);
    
    UFUNCTION(BlueprintCallable)
    static void SetStaticColor(EChromaSDKDeviceEnum::Type device, const FLinearColor& Color);
    
    UFUNCTION(BlueprintCallable)
    static void SetMouseLedColor(EChromaSDKMouseLed::Type led, const FLinearColor& colorParam, UPARAM(Ref) TArray<FChromaSDKColors>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysNonZeroColorName(const FString& AnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysNonZeroColorAllFramesName(const FString& AnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysNonZeroColorAllFrames(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysNonZeroColor(int32 animationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorRGBName(const FString& AnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorRGB(int32 animationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorName(const FString& AnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorAllFramesRGBName(const FString& AnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorAllFramesRGB(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorAllFramesName(const FString& AnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColorAllFrames(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeysColor(int32 animationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyRowColumnColorName(const FString& AnimationName, const int32 FrameIndex, const int32 Row, const int32 Column, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyNonZeroColorName(const FString& AnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyNonZeroColorAllFramesName(const FString& AnimationName, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyNonZeroColorAllFrames(int32 animationId, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyNonZeroColor(int32 animationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyColorName(const FString& AnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyColorAllFramesName(const FString& AnimationName, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyColorAllFrames(int32 animationId, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyColor(int32 animationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void SetKeyboardKeyColor(EChromaSDKKeyboardKey::Type Key, const FLinearColor& colorParam, UPARAM(Ref) TArray<FChromaSDKColors>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static void SetIdleAnimationName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void SetCurrentFrameName(const FString& AnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void SetCurrentFrame(int32 animationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void SetChromaCustomFlagName(const FString& AnimationName, bool Flag);
    
    UFUNCTION(BlueprintCallable)
    static void SetChromaCustomColorAllFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void ReverseAllFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void ReverseAllFrames(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void ReduceFramesName(const FString& AnimationName, int32 N);
    
    UFUNCTION(BlueprintCallable)
    static void ReduceFrames(int32 animationId, int32 N);
    
    UFUNCTION(BlueprintCallable)
    static void PreviewFrameName(const FString& AnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static int32 PreviewFrame(int32 animationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void PlayAnimations(const TArray<FString>& animationNames, bool Loop);
    
    UFUNCTION(BlueprintCallable)
    static void PlayAnimationName(const FString& AnimationName, bool Loop);
    
    UFUNCTION(BlueprintCallable)
    static void PlayAnimationComposite(const FString& AnimationName, bool Loop);
    
    UFUNCTION(BlueprintCallable)
    static void PlayAnimation(const FString& AnimationName, bool Loop);
    
    UFUNCTION(BlueprintCallable)
    static void OverrideFrameDurationName(const FString& AnimationName, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void OpenAnimationFromMemory(const TArray<uint8>& Data, const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetNonZeroColorsName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetNonZeroColorsAllFramesName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetNonZeroColorsAllFrames(int32 animationId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetNonZeroColors(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetColorsName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetColorsAllFramesName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetColorsAllFrames(int32 animationId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void OffsetColors(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyTargetColorLerpAllFramesName(const FString& AnimationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyNonZeroTargetColorLerpAllFramesName(const FString& AnimationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyNonZeroTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityName(const FString& AnimationName, int32 frameId, float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityColorAllFrames(int32 animationId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityAllFramesName(const FString& AnimationName, float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensityAllFrames(int32 animationId, float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyIntensity(int32 animationId, int32 frameId, float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyColorLerpAllFramesName(const FString& AnimationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
    
    UFUNCTION(BlueprintCallable)
    static void MultiplyColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesRGBName(const FString& AnimationName, int32 frameCount, float Duration, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesRGB(int32 animationId, int32 frameCount, float Duration, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesRandomName(const FString& AnimationName, int32 frameCount, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesRandomBlackAndWhiteName(const FString& AnimationName, int32 frameCount, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesRandomBlackAndWhite(int32 animationId, int32 frameCount, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesRandom(int32 animationId, int32 frameCount, float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFramesName(const FString& AnimationName, int32 frameCount, float Duration, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void MakeBlankFrames(int32 animationId, int32 frameCount, float Duration, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void LoadAnimationName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void LoadAnimation(const int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static int32 LerpColorBGR(int32 From, int32 To, float T);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor LerpColor(FLinearColor colorParam1, FLinearColor colorParam2, float T);
    
    UFUNCTION(BlueprintCallable)
    static float Lerp(float Start, float End, float amt);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlatformWindows();
    
    UFUNCTION(BlueprintCallable)
    static bool IsInitialized();
    
    UFUNCTION(BlueprintCallable)
    static bool IsAnimationTypePlaying(TEnumAsByte<EChromaSDKDeviceEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAnimationPlaying(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void InvertColorsAllFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void InvertColorsAllFrames(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void InsertFrameName(const FString& AnimationName, int32 sourceFrame, int32 targetFrame);
    
    UFUNCTION(BlueprintCallable)
    static void InsertFrame(int32 animationId, int32 sourceFrame, int32 targetFrame);
    
    UFUNCTION(BlueprintCallable)
    static void InsertDelayName(const FString& AnimationName, int32 frameId, int32 Delay);
    
    UFUNCTION(BlueprintCallable)
    static void InsertDelay(int32 animationId, int32 frameId, int32 Delay);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetRGB(int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayingAnimationId(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayingAnimationCount();
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetMouseLedColor(TEnumAsByte<EChromaSDKMouseLed::Type> led, UPARAM(Ref) TArray<FChromaSDKColors>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMaxRow(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMaxLeds(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMaxColumn(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetKeyColorName(const FString& AnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetKeyColor(int32 animationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetKeyboardRzKey(TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EChromaSDKKeyboardKey::Type> GetKeyboardRazerKey(FKey Key);
    
    UFUNCTION(BlueprintCallable)
    static FLinearColor GetKeyboardKeyColor(TEnumAsByte<EChromaSDKKeyboardKey::Type> Key, UPARAM(Ref) TArray<FChromaSDKColors>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetFrameCountName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetFrameCount(const int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentFrameName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentFrame(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetBGRInt(int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static FString GetAnimationName(const int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetAnimationIdByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetAnimationId(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetAnimationCount();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetAnimation(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColorAllFrames(int32 animationId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillZeroColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdRGBColorsAllFramesRGBName(const FString& AnimationName, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdRGBColorsAllFramesRGB(int32 animationId, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsRGBName(const FString& AnimationName, int32 frameId, int32 Threshold, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsRGB(int32 animationId, int32 frameId, int32 Threshold, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsMinMaxAllFramesRGBName(const FString& AnimationName, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsMinMaxAllFramesRGB(int32 animationId, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsAllFramesRGBName(const FString& AnimationName, int32 Threshold, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsAllFramesRGB(int32 animationId, int32 Threshold, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsAllFramesName(const FString& AnimationName, int32 Threshold, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillThresholdColorsAllFrames(int32 animationId, int32 Threshold, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsName(const FString& AnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsBlackAndWhiteName(const FString& AnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsBlackAndWhiteAllFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsBlackAndWhiteAllFrames(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsBlackAndWhite(int32 animationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsAllFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColorsAllFrames(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void FillRandomColors(int32 animationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColorAllFrames(int32 animationId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillNonZeroColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorRGBName(const FString& AnimationName, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorRGB(int32 animationId, int32 frameId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorName(const FString& AnimationName, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorAllFramesRGBName(const FString& AnimationName, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorAllFramesRGB(int32 animationId, int32 Red, int32 Green, int32 Blue);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorAllFramesName(const FString& AnimationName, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillColorAllFrames(int32 animationId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FillColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static void FadeStartFramesName(const FString& AnimationName, int32 fade);
    
    UFUNCTION(BlueprintCallable)
    static void FadeStartFrames(int32 animationId, int32 fade);
    
    UFUNCTION(BlueprintCallable)
    static void FadeEndFramesName(const FString& AnimationName, int32 fade);
    
    UFUNCTION(BlueprintCallable)
    static void FadeEndFrames(int32 animationId, int32 fade);
    
    UFUNCTION(BlueprintCallable)
    static void DuplicateMirrorFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void DuplicateMirrorFrames(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void DuplicateFramesName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void DuplicateFrames(int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void DuplicateFirstFrameName(const FString& AnimationName, int32 frameCount);
    
    UFUNCTION(BlueprintCallable)
    static void DuplicateFirstFrame(int32 animationId, int32 frameCount);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FChromaSDKColors> CreateRandomColorsBlackAndWhite2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLinearColor> CreateRandomColorsBlackAndWhite1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FChromaSDKColors> CreateRandomColors2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLinearColor> CreateRandomColors1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FChromaSDKColors> CreateColors2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLinearColor> CreateColors1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static void CopyZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CopyZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroTargetAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroTargetAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroKeysColorAllFrames(int32 sourceAnimationId, int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroKeysColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroKeyColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyKeysColorAllFrames(int32 sourceAnimationId, int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyKeysColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void CopyKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static void CopyKeyColor(int32 sourceAnimationId, int32 targetAnimationId, int32 FrameIndex, TEnumAsByte<EChromaSDKKeyboardKey::Type> Key);
    
    UFUNCTION(BlueprintCallable)
    static void CopyAnimationName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CopyAnimation(int32 sourceAnimationId, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CopyAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CopyAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void CopyAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void CloseAnimationName(const FString& AnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void CloseAnimation(const int32 animationId);
    
    UFUNCTION(BlueprintCallable)
    static void CloseAll();
    
    UFUNCTION(BlueprintCallable)
    static void ClearAnimationType(EChromaSDKDeviceEnum::Type device);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAll();
    
    UFUNCTION(BlueprintCallable)
    static int32 ChromaSDKUnInit();
    
    UFUNCTION(BlueprintCallable)
    static int32 ChromaSDKSetEffect(const FChromaSDKGuid& EffectId);
    
    UFUNCTION(BlueprintCallable)
    static int32 ChromaSDKInitSDK(const FChromaSDKAppInfoType& appInfo);
    
    UFUNCTION(BlueprintCallable)
    static int32 ChromaSDKInit();
    
    UFUNCTION(BlueprintCallable)
    static int32 ChromaSDKDeleteEffect(const FChromaSDKGuid& EffectId);
    
    UFUNCTION(BlueprintCallable)
    static FChromaSDKEffectResult ChromaSDKCreateEffectStatic(TEnumAsByte<EChromaSDKDeviceEnum::Type> device, const FLinearColor& colorParam);
    
    UFUNCTION(BlueprintCallable)
    static FChromaSDKEffectResult ChromaSDKCreateEffectNone(TEnumAsByte<EChromaSDKDeviceEnum::Type> device);
    
    UFUNCTION(BlueprintCallable)
    static FChromaSDKEffectResult ChromaSDKCreateEffectKeyboardCustom2D(const TArray<FChromaSDKColors>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static FChromaSDKEffectResult ChromaSDKCreateEffectCustom2D(TEnumAsByte<EChromaSDKDevice2DEnum::Type> device, const TArray<FChromaSDKColors>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static FChromaSDKEffectResult ChromaSDKCreateEffectCustom1D(TEnumAsByte<EChromaSDKDevice1DEnum::Type> device, const TArray<FLinearColor>& Colors);
    
    UFUNCTION(BlueprintCallable)
    static void AppendAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void AppendAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 Offset);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);
    
    UFUNCTION(BlueprintCallable)
    static void AddNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);
    
};

