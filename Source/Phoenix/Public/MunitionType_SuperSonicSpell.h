#pragma once
#include "CoreMinimal.h"
#include "MunitionType_Base.h"
#include "EEnemyShieldBreaker.h"
#include "MunitionSpellInterface.h"
#include "MunitionType_SuperSonicSpell.generated.h"

class AActor;
class ASpellTool;

UCLASS(Blueprintable)
class AMunitionType_SuperSonicSpell : public AMunitionType_Base, public IMunitionSpellInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASpellTool* SpellTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlwaysHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IncreaseRangeBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreProtego;
    
    AMunitionType_SuperSonicSpell(const FObjectInitializer& ObjectInitializer);
    
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
    
    UFUNCTION(BlueprintCallable)
    ASpellTool* GetSpellTool() const override PURE_VIRTUAL(GetSpellTool, return NULL;);
    
};

