#pragma once
#include "CoreMinimal.h"
#include "ModFilter_ItemProperty_Base.h"
#include "ModFilter_ItemProperty_IsUseablePlant.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_ItemProperty_IsUseablePlant : public UModFilter_ItemProperty_Base {
    GENERATED_BODY()
public:
    UModFilter_ItemProperty_IsUseablePlant();
};

