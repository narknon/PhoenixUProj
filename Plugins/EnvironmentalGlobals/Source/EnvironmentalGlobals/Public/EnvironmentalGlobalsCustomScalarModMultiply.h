#pragma once
#include "CoreMinimal.h"
#include "EnvironmentalGlobalsCustomScalarModSingleValue.h"
#include "EnvironmentalGlobalsCustomScalarModMultiply.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UEnvironmentalGlobalsCustomScalarModMultiply : public UEnvironmentalGlobalsCustomScalarModSingleValue {
    GENERATED_BODY()
public:
    UEnvironmentalGlobalsCustomScalarModMultiply();
};

