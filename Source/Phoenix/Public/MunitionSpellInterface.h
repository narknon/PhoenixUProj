#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EEnemyShieldBreaker.h"
#include "MunitionSpellInterface.generated.h"

class AActor;
class ASpellTool;

UINTERFACE(BlueprintType, MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UMunitionSpellInterface : public UInterface {
    GENERATED_BODY()
};

class IMunitionSpellInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual void SetPlayerShieldBreaker(bool ShieldBreaker) PURE_VIRTUAL(SetPlayerShieldBreaker,);
    
    UFUNCTION(BlueprintCallable)
    virtual void SetEnemyShieldBreaker(EEnemyShieldBreaker ShieldBreaker) PURE_VIRTUAL(SetEnemyShieldBreaker,);
    
    UFUNCTION(BlueprintCallable)
    virtual bool IsUnblockable(const AActor* SpellTarget) const PURE_VIRTUAL(IsUnblockable, return false;);
    
    UFUNCTION(BlueprintCallable)
    virtual bool IsPlayerShieldBreaker() const PURE_VIRTUAL(IsPlayerShieldBreaker, return false;);
    
    UFUNCTION(BlueprintCallable)
    virtual EEnemyShieldBreaker IsEnemyShieldBreaker() const PURE_VIRTUAL(IsEnemyShieldBreaker, return EEnemyShieldBreaker::None;);
    
    UFUNCTION(BlueprintCallable)
    virtual ASpellTool* GetSpellTool() const PURE_VIRTUAL(GetSpellTool, return NULL;);
    
};

