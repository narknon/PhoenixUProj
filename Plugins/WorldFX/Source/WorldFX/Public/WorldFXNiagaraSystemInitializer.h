#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldFXNiagaraSystemInitializer.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class UWorldFXNiagaraSystemInitializer : public UObject {
    GENERATED_BODY()
public:
    UWorldFXNiagaraSystemInitializer();
};

