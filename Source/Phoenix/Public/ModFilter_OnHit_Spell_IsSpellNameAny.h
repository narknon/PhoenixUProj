#pragma once
#include "CoreMinimal.h"
#include "ModFilter_OnHit_Base.h"
#include "ModFilter_OnHit_Spell_IsSpellNameAny.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_OnHit_Spell_IsSpellNameAny : public UModFilter_OnHit_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpellNames;
    
public:
    UModFilter_OnHit_Spell_IsSpellNameAny();
};

