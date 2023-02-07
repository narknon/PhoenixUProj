#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "SocialActionTypes.h"
#include "SocialSemanticIDs.h"
#include "RPGTriggerEffect_OnHitBySpell.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class URPGTriggerEffect_OnHitBySpell : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckSpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckSpellName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialActionTypes> SpellName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
public:
    URPGTriggerEffect_OnHitBySpell();
};

