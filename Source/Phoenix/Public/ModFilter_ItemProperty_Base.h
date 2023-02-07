#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_ItemProperty_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_ItemProperty_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_ItemProperty_Base();
};

