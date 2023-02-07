#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETimeRigPlayerState.h"
#include "TimeRigCriticalEventDynamicDelegateDelegate.h"
#include "TimeRigEventDynamicDelegateDelegate.h"
#include "TimeRigOnPlaybackStartedDynamicDelegate.h"
#include "TimeRigOnPlaybackStartingDelegate.h"
#include "TimeRigPlayer.generated.h"

class UTimeRig;
class UTimeRigInstanceContext;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigPlayer : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BranchID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig* TimeRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRigInstanceContext* InstanceContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlaybackScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RoundTimeToFPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondsRemainingForAlmostCompleteTrigger;
    
public:
    UTimeRigPlayer();
    UFUNCTION(BlueprintCallable)
    void StopIn(float SecondsFromNow, float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void StopImmediate();
    
    UFUNCTION(BlueprintCallable)
    void Stop();
    
    UFUNCTION(BlueprintCallable)
    bool Skip();
    
    UFUNCTION(BlueprintCallable)
    void SetTime(float Seconds);
    
    UFUNCTION(BlueprintCallable)
    void SetSecondsRemainingForAlmostCompleteTrigger(float Seconds);
    
    UFUNCTION(BlueprintCallable)
    void SetRoundTimeToFPS(float FPS);
    
    UFUNCTION(BlueprintCallable)
    void SetPlaybackScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    bool SetOnPlaybackStarting(FTimeRigOnPlaybackStarting InOnPlaybackStarting);
    
    UFUNCTION(BlueprintCallable)
    bool SetOnPlaybackStarted(FTimeRigOnPlaybackStartedDynamic InOnPlaybackStarted);
    
    UFUNCTION(BlueprintCallable)
    bool SetLooping(bool LoopingEnabled);
    
    UFUNCTION(BlueprintCallable)
    void RewindToCurrentStartOf(UClass* ActionType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ReadyToPlay() const;
    
    UFUNCTION(BlueprintCallable)
    bool PlayImmediate(FName InActivationSource);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PlaybackHasStarted() const;
    
    UFUNCTION(BlueprintCallable)
    bool Play(FName InActivationSource);
    
    UFUNCTION(BlueprintCallable)
    void PauseAfterCurrentEndOf(UClass* ActionType);
    
    UFUNCTION(BlueprintCallable)
    void Pause();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWantingToPlayButNotPlaying() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTicking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStopping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlaying() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLooping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInitializing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInitialized() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTimeRig* GetTimeRig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSecondsRemainingForAlmostCompleteTrigger() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRoundTimeToFPS() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETimeRigPlayerState GetPlayerState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPlaybackScale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEndTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBeginTime() const;
    
    UFUNCTION(BlueprintCallable)
    void FastForwardToNextStartOf(UClass* ActionType);
    
    UFUNCTION(BlueprintCallable)
    void FastForwardToNextEndOf(UClass* ActionType);
    
    UFUNCTION(BlueprintCallable)
    void FastForwardToEvent(const FName& EventName);
    
    UFUNCTION(BlueprintCallable)
    void FastForwardToCurrentEndOf(UClass* ActionType);
    
    UFUNCTION(BlueprintCallable)
    bool EventOccursNow(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    bool EventOccursAt(FName EventName, float SecondsFromNow);
    
    UFUNCTION(BlueprintCallable)
    bool AddEventHandler(FName EventName, const FTimeRigEventDynamicDelegate& Handler);
    
    UFUNCTION(BlueprintCallable)
    bool AddCriticalEventHandler(FName EventName, const FTimeRigCriticalEventDynamicDelegate& Handler);
    
};

