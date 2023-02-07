#pragma once
#include "CoreMinimal.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_IsCritical.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_IsCritical : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
    UModFilter_DealDamage_IsCritical();
};

