#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Curves/CurveFloat.h"
#include "HitTrackerTypes.h"
#include "RPGAbilityEventListener.h"
#include "RPGHitTracker.h"
#include "RPGAbilityEventListener_OnTargetHitWithSpells.generated.h"

class AActor;
class AWandTool;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnTargetHitWithSpells : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    HitTrackerTypes TargetChainRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    HitTrackerTypes SpellChainRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetOnBeingHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetOnFailedSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTimeBetweenHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChanceBased;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumRequiredHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TriggerChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FRPGHitTracker> TrackedHits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWandTool* Wand;
    
public:
    URPGAbilityEventListener_OnTargetHitWithSpells();
protected:
    UFUNCTION(BlueprintCallable)
    void OnDamageReceived(AActor* Target, AActor* Instigator, float Damage, const FHitResult& Hit);
    
};

