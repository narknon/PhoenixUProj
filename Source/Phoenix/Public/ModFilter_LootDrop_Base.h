#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_LootDrop_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_LootDrop_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_LootDrop_Base();
};

