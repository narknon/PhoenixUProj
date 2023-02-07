#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnvironmentalGlobalsCustomScalarMod.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsCustomScalarMod : public UObject {
    GENERATED_BODY()
public:
    UEnvironmentalGlobalsCustomScalarMod();
};

