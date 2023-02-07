#pragma once
#include "CoreMinimal.h"
#include "StencilManagerExternalControl.h"
#include "StencilManagerExternalSystemControl.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerExternalSystemControl : public UStencilManagerExternalControl {
    GENERATED_BODY()
public:
    UStencilManagerExternalSystemControl();
};

