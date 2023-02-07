#pragma once
#include "CoreMinimal.h"
#include "TimeOverrideBase.h"
#include "TimeOverrideTimeOnly.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class DAYNIGHT_API UTimeOverrideTimeOnly : public UTimeOverrideBase {
    GENERATED_BODY()
public:
    UTimeOverrideTimeOnly();
};

