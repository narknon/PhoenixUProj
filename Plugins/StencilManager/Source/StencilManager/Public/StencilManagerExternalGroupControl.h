#pragma once
#include "CoreMinimal.h"
#include "StencilManagerExternalControl.h"
#include "StencilManagerExternalGroupControl.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerExternalGroupControl : public UStencilManagerExternalControl {
    GENERATED_BODY()
public:
    UStencilManagerExternalGroupControl();
};

