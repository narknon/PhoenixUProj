#pragma once
#include "CoreMinimal.h"
#include "ModFilter_ItemProperty_Base.h"
#include "ModFilter_ItemProperty_IsPotion.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_ItemProperty_IsPotion : public UModFilter_ItemProperty_Base {
    GENERATED_BODY()
public:
    UModFilter_ItemProperty_IsPotion();
};

