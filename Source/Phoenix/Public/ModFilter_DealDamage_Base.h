#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_DealDamage_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_DealDamage_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_DealDamage_Base();
};

