#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MunitionType_Base.h"
#include "EEnemyShieldBreaker.h"
#include "MunitionSpellInterface.h"
#include "Templates/SubclassOf.h"
#include "MunitionType_AOESpell.generated.h"

class AActor;
class ASpellTool;
class UAkAudioEvent;
class UCurveFloat;
class UDamageType;
class UParticleSystem;

UCLASS(Blueprintable)
class AMunitionType_AOESpell : public AMunitionType_Base, public IMunitionSpellInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_hitVictimInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageType> m_damageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* m_explosionFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* m_explosionSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayAtBottomOfInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_stopAtCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHitAllBrokenPieces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_delayedDeathTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBreakBlockFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionNoiseEventLoudness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionNoiseEventMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RadiusPercentAtTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpellTool* SpellTool;
    
    AMunitionType_AOESpell();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHit(const FHitResult& HitResult, bool bDestroyed, bool bHit, bool bBlocked, bool bFailed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpellTool* GetSpellTool() const;
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void SetPlayerShieldBreaker(bool ShieldBreaker) override PURE_VIRTUAL(SetPlayerShieldBreaker,);
    
    UFUNCTION(BlueprintCallable)
    void SetEnemyShieldBreaker(EEnemyShieldBreaker ShieldBreaker) override PURE_VIRTUAL(SetEnemyShieldBreaker,);
    
    UFUNCTION(BlueprintCallable)
    bool IsUnblockable(const AActor* SpellTarget) const override PURE_VIRTUAL(IsUnblockable, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerShieldBreaker() const override PURE_VIRTUAL(IsPlayerShieldBreaker, return false;);
    
    UFUNCTION(BlueprintCallable)
    EEnemyShieldBreaker IsEnemyShieldBreaker() const override PURE_VIRTUAL(IsEnemyShieldBreaker, return EEnemyShieldBreaker::None;);
    
};

