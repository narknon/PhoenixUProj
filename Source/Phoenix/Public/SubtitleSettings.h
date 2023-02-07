#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EStandardManagedPriority.h"
#include "SubtitleSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class USubtitleSettings : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FAudioPriorityChangedHandler, int32, NewValue);
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioPriorityCutoff;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioPrioritySuppress;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioLowPrioritySuppressDistance;
    
    USubtitleSettings();
    UFUNCTION(BlueprintCallable)
    static void StartSettingAudioPrioritySuppress(int32 NewValue, EStandardManagedPriority Priority, const UObject* Requestor);
    
    UFUNCTION(BlueprintCallable)
    static void StartSettingAudioPriorityCutoff(int32 NewValue, EStandardManagedPriority Priority, const UObject* Requestor);
    
    UFUNCTION(BlueprintCallable)
    static void StartSettingAudioLowPriorityDistanceSuppress(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    static void StartOverrideSubtitlePosition(const UObject* Requestor, const FVector2D OverridePos);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetOverrideSubtitlePositionState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetAudioPrioritySuppress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetAudioPriorityCutoff();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetAudioLowPrioritySuppressDistance();
    
    UFUNCTION(BlueprintCallable)
    static void FinishSettingAudioPrioritySuppress(EStandardManagedPriority Priority, const UObject* Requestor);
    
    UFUNCTION(BlueprintCallable)
    static void FinishSettingAudioPriorityCutoff(EStandardManagedPriority Priority, const UObject* Requestor);
    
    UFUNCTION(BlueprintCallable)
    static void FinishSettingAudioLowPriorityDistanceSuppress();
    
    UFUNCTION(BlueprintCallable)
    static void FinishOverrideSubtitlePosition(const UObject* Requestor);
    
    UFUNCTION(BlueprintCallable)
    static void AddAudioPrioritySuppressChangedHandler(USubtitleSettings::FAudioPriorityChangedHandler AudioPrioritySuppressHandler);
    
    UFUNCTION(BlueprintCallable)
    static void AddAudioPriorityCutoffChangedHandler(USubtitleSettings::FAudioPriorityChangedHandler AudioPriorityCuttoffHandler);
    
};

