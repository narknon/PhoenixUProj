#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_Focus_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_Focus_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_Focus_Base();
};

