#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_ObjectState_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_ObjectState_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_ObjectState_Base();
};

