#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ESanctuaryIdentity.h"
#include "IdentityParticleSystemsData.h"
#include "OnCameraOverlapEndDelegate.h"
#include "OnCameraOverlapStartDelegate.h"
#include "OnMoveEmittersDelegate.h"
#include "OnPlayerOverlapEndDelegate.h"
#include "OnPlayerOverlapStartDelegate.h"
#include "ParticleSystemsData.h"
#include "StreamingPlaceholderBase.h"
#include "SanctuaryStreamingVFXTriggerVolume.generated.h"

class AActor;
class UBoxComponent;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASanctuaryStreamingVFXTriggerVolume : public AStreamingPlaceholderBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSwapWhenIdentityChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIdentityParticleSystemsData IdentityParticleSystems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FParticleSystemsData DefaultSystem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerOverlapStart OnPlayerOverlapStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerOverlapEnd OnPlayerOverlapEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCameraOverlapStart OnCameraOverlapStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCameraOverlapEnd OnCameraOverlapEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMoveEmitters OnMoveEmitters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* BoxComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayerTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CameraTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayerRelativeMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UParticleSystemComponent*> ParticleEffectsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> NiagaraEffectsList;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsActivated;
    
public:
    ASanctuaryStreamingVFXTriggerVolume(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void OnParticleSystemFinished(UParticleSystemComponent* PSystem);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnOverlapStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNiagaraFinished(UNiagaraComponent* PSystem);
    
    UFUNCTION(BlueprintCallable)
    void OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity);
    
};

