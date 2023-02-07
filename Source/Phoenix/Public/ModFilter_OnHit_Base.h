#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_OnHit_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_OnHit_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_OnHit_Base();
};

