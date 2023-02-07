#pragma once
#include "CoreMinimal.h"
#include "TimeOverrideBase.h"
#include "TimeOverrideDateTime.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class DAYNIGHT_API UTimeOverrideDateTime : public UTimeOverrideBase {
    GENERATED_BODY()
public:
    UTimeOverrideDateTime();
};

