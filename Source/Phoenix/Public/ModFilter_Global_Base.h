#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_Global_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_Global_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_Global_Base();
};

