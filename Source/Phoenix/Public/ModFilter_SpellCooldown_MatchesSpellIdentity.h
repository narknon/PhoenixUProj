#pragma once
#include "CoreMinimal.h"
#include "SelectableName.h"
#include "ModFilter_SpellCooldown_Base.h"
#include "ModFilter_SpellCooldown_MatchesSpellIdentity.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_SpellCooldown_MatchesSpellIdentity : public UModFilter_SpellCooldown_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableName SpellIdentity;
    
public:
    UModFilter_SpellCooldown_MatchesSpellIdentity();
};

