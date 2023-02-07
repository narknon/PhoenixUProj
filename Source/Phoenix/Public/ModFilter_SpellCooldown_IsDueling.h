#pragma once
#include "CoreMinimal.h"
#include "ModFilter_SpellCooldown_Base.h"
#include "ModFilter_SpellCooldown_IsDueling.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_SpellCooldown_IsDueling : public UModFilter_SpellCooldown_Base {
    GENERATED_BODY()
public:
    UModFilter_SpellCooldown_IsDueling();
};

