#pragma once
#include "CoreMinimal.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_Spell_IsSpellName.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_Spell_IsSpellName : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellName;
    
public:
    UModFilter_DealDamage_Spell_IsSpellName();
};

