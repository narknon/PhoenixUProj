#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "PerPlatformProperties.h"
#include "GameplayTagContainer.h"
#include "EWandLinkResult.h"
#include "Templates/SubclassOf.h"
#include "WandLinkStage.h"
#include "WandLinkObject.generated.h"

class AMunitionType_Base;
class AWandLinkProjectile;
class UActorProvider;
class UAkAudioEvent;
class UCameraShakeBase;
class UInteractionArchitectAsset;
class UMultiFX2_Base;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;
class USceneRigPlayer;
class UWandLinkKillBystander;

UCLASS(Blueprintable)
class AWandLinkObject : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* ProtagonistProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* AntagonistProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* TeleportLocation1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* TeleportLocation2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UIRenderScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageToPlayerOnFailPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ProtagonistMuzzleFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ProtagonistProjectileFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ProtagonistBeamFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ProtagonistNudgeFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ProtagonistSuccessFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* AntagonistMuzzleFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* AntagonistProjectileFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> AntagonistBeamFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* AntagonistNudgeFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* AntagonistSuccessFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> BystanderBeamFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BystanderBeamTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ZapBystanderMunitionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZapForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZapMiscTimeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZapMiscTimeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZapTerrainChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ZapTerrainRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZapTerrainZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* InitialClashMunitionDataAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashDistance_Close;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer InitialClashMunitionTags_Close;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashForce_Close_Inner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashForce_Close_Outer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashDamagePct_Close;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashDistance_Med;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer InitialClashMunitionTags_Med;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashForce_Med_Inner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashForce_Med_Outer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashDamagePct_Med;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashDistance_Far;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer InitialClashMunitionTags_Far;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashForce_Far;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialClashDamagePct_Far;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* ClashVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ClashStartSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LinkLoopSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LinkLoopEndSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LightningBoltSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ClashExplodeSFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LightningBoltMotionFXEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProtagonistWandTipSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AntagonistWandTipSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraShakeBase> ClashCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> KillBystandersMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerPlatformInt SimpleBlowBystanders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWandLinkStage> WandLinkStages;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> BlowBystanders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> LastMunitionDataAssets;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneRigPlayer> CurrentSceneRigPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AWandLinkProjectile* ProtagonistProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AWandLinkProjectile* AntagonistProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* ProtagonistMuzzle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* AntagonistMuzzle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* VFXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* LastCaller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWandLinkKillBystander*> KillBystanderArray;
    
public:
    AWandLinkObject(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WandLinkStarted();
    
    UFUNCTION(BlueprintCallable)
    void WandLinkInputSuccess();
    
    UFUNCTION(BlueprintCallable)
    void WandLinkInputFail();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WandLinkInitialized();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WandLinkEnded();
    
    UFUNCTION(BlueprintCallable)
    bool GetUIHidden();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetProtagonist();
    
    UFUNCTION(BlueprintCallable)
    EWandLinkResult GetLethal();
    
    UFUNCTION(BlueprintCallable)
    int32 GetCurrentStage();
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentRatio();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetAntagonist();
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkSuspend(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkSuccessFX(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkStop(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkStart(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkKillBystanders(const UObject* Caller, float KillPct);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkInitialize(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkGameOver(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkForward(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkFailFX(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkDefend(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkBackward(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_WandLinkAdvanceStage(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_TeleportLocation2(const UObject* Caller);
    
    UFUNCTION(BlueprintCallable)
    void Event_TeleportLocation1(const UObject* Caller);
    
};

