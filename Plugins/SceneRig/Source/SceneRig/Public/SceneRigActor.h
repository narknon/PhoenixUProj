#pragma once
#include "CoreMinimal.h"
#include "SpawnedActorHost.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "ETimeRigInitializingBehavior.h"
#include "TimeRigEventDynamicDelegateDelegate.h"
#include "SceneRigParameters.h"
#include "TimeRigEventWithActorDynamicDelegateDelegate.h"
#include "SceneRigActor.generated.h"

class ATriggerBase;
class ULevelStreaming;
class UPrimitiveComponent;
class USceneComponent;
class USceneRig;
class USceneRigPlayer;
class USceneRigProvider;
class USceneRigStageContainer;

UCLASS(Blueprintable)
class SCENERIG_API ASceneRigActor : public AActor, public ISpawnedActorHost {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetPlaying, bool, bPlaying);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlaybackAlmostComplete);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoInitialize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoadStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreatePreviewActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKey DebugTriggerSceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoopIndefinitely;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ATriggerBase>> TriggerVolumes;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* SceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* SceneRigProvider;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LookupAlias;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneRigPlayer> SceneRigPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameters SceneInterface;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSetPlaying OnSetPlaying;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlaybackAlmostComplete OnPlaybackAlmostComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USceneRigStageContainer* StageContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreaming*> StreamedStages;
    
public:
    ASceneRigActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void StopRepeatedPlay(bool StopCurrentlyPlaying);
    
    UFUNCTION(BlueprintCallable)
    void StopImmediate();
    
    UFUNCTION(BlueprintCallable)
    void Stop();
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* StartRepeatedPlay(float MinRepeatDelay, float MaxRepeatDelay, ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable)
    void ShowSkipUI(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetPlaybackScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    void Resume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PlayingOnRepeat() const;
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* PlayImmediate();
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* Play(ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable)
    void Pause();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSceneRigBeingSkipped(TSoftObjectPtr<USceneRig> NewSceneRig);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlaying() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActive() const;
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* Initialize(ETimeRigInitializingBehavior InitializingBehaviorType);
    
    UFUNCTION(BlueprintCallable)
    float GetTimeRemaining();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneRigPlayer* GetSceneRigPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneRig* GetSceneRig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPlaybackScale() const;
    
    UFUNCTION(BlueprintCallable)
    USceneRigPlayer* DebugTriggerPlay();
    
    UFUNCTION(BlueprintCallable)
    void AssignSceneRig(USceneRig* InSceneRig);
    
    UFUNCTION(BlueprintCallable)
    void AddStartHandler(const FTimeRigEventDynamicDelegate& Handler);
    
    UFUNCTION(BlueprintCallable)
    void AddOnCleanupHandler(const FTimeRigEventDynamicDelegate& Handler);
    
    UFUNCTION(BlueprintCallable)
    void AddFinishHandler(const FTimeRigEventDynamicDelegate& Handler);
    
    UFUNCTION(BlueprintCallable)
    void AddEventHandlerWithActor(FName EventName, FTimeRigEventWithActorDynamicDelegate Delegate);
    
    UFUNCTION(BlueprintCallable)
    void AddEventHandler(FName EventName, FTimeRigEventDynamicDelegate Delegate);
    
    
    // Fix for true pure virtual functions not being implemented
};

