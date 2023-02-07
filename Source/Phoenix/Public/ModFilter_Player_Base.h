#pragma once
#include "CoreMinimal.h"
#include "ModFilter_Global_Base.h"
#include "ModFilter_Player_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_Player_Base : public UModFilter_Global_Base {
    GENERATED_BODY()
public:
    UModFilter_Player_Base();
};

