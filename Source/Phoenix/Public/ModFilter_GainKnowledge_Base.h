#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_GainKnowledge_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_GainKnowledge_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_GainKnowledge_Base();
};

