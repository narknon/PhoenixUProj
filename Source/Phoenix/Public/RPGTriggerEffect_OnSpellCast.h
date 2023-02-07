#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_OnSpellCast.generated.h"

class AActor;
class URPGAbility;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_OnSpellCast : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpellNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyDiamondSpells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URPGTriggerEffect_Base*> TriggerEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URPGAbility* OwnerAbility;
    
public:
    URPGTriggerEffect_OnSpellCast();
};

