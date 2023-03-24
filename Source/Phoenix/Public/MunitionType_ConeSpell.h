#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MunitionType_Base.h"
#include "EEnemyShieldBreaker.h"
#include "MunitionSpellInterface.h"
#include "Templates/SubclassOf.h"
#include "MunitionType_ConeSpell.generated.h"

class AActor;
class ASpellTool;
class UAkAudioEvent;
class UDamageType;
class UParticleSystem;

UCLASS(Blueprintable)
class AMunitionType_ConeSpell : public AMunitionType_Base, public IMunitionSpellInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageType> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopAtCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ExplosionVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ExplosionSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpellTool* SpellTool;
    
    AMunitionType_ConeSpell(const FObjectInitializer& ObjectInitializer);
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

