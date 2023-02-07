#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_UseItem_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_UseItem_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_UseItem_Base();
};

