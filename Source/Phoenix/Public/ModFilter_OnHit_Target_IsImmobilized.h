#pragma once
#include "CoreMinimal.h"
#include "ModFilter_OnHit_Base.h"
#include "ModFilter_OnHit_Target_IsImmobilized.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_OnHit_Target_IsImmobilized : public UModFilter_OnHit_Base {
    GENERATED_BODY()
public:
    UModFilter_OnHit_Target_IsImmobilized();
};

