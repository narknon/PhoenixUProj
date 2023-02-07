#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Curves/CurveFloat.h"
#include "RPGAbilityEventListener_Base.h"
#include "SocialSemanticIDs.h"
#include "RPGAbilityEventListener_ReduceCooldownOnDamage.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_ReduceCooldownOnDamage : public URPGAbilityEventListener_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TimePerDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckSpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SpellGroupName;
    
public:
    URPGAbilityEventListener_ReduceCooldownOnDamage();
protected:
    UFUNCTION(BlueprintCallable)
    void OnDamageReceived(AActor* Target, AActor* Instigator, float Damage, const FHitResult& Hit);
    
};

