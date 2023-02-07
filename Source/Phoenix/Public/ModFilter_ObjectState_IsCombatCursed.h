#pragma once
#include "CoreMinimal.h"
#include "ModFilter_ObjectState_Base.h"
#include "ModFilter_ObjectState_IsCombatCursed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_ObjectState_IsCombatCursed : public UModFilter_ObjectState_Base {
    GENERATED_BODY()
public:
    UModFilter_ObjectState_IsCombatCursed();
};

