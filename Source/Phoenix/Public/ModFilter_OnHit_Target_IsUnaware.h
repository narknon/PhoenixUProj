#pragma once
#include "CoreMinimal.h"
#include "ModFilter_OnHit_Base.h"
#include "ModFilter_OnHit_Target_IsUnaware.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_OnHit_Target_IsUnaware : public UModFilter_OnHit_Base {
    GENERATED_BODY()
public:
    UModFilter_OnHit_Target_IsUnaware();
};

