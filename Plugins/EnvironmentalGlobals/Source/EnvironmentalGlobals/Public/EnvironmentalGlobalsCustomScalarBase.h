#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnvironmentalGlobalsCustomScalarBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalarBase : public UObject {
    GENERATED_BODY()
public:
    UEnvironmentalGlobalsCustomScalarBase();
};

