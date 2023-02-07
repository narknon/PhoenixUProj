#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_SpellCooldown_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_SpellCooldown_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_SpellCooldown_Base();
};

