#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnvironmentalGlobalsVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsVar : public UObject {
    GENERATED_BODY()
public:
    UEnvironmentalGlobalsVar();
};

