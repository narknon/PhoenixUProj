#pragma once
#include "CoreMinimal.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_IsRanged.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_IsRanged : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
    UModFilter_DealDamage_IsRanged();
};

