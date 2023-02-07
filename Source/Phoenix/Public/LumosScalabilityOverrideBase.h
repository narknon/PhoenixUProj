#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LumosScalabilityOverrideBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ULumosScalabilityOverrideBase : public UObject {
    GENERATED_BODY()
public:
    ULumosScalabilityOverrideBase();
};

