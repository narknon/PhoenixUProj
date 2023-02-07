#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StencilManagerExternalControl.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class STENCILMANAGER_API UStencilManagerExternalControl : public UObject {
    GENERATED_BODY()
public:
    UStencilManagerExternalControl();
};

