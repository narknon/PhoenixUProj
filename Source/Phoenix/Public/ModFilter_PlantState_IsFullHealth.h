#pragma once
#include "CoreMinimal.h"
#include "ModFilter_ObjectState_Base.h"
#include "ModFilter_PlantState_IsFullHealth.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_PlantState_IsFullHealth : public UModFilter_ObjectState_Base {
    GENERATED_BODY()
public:
    UModFilter_PlantState_IsFullHealth();
};

