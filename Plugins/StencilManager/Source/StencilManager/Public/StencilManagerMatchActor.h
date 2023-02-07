#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StencilManagerMatchActor.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActor : public UObject {
    GENERATED_BODY()
public:
    UStencilManagerMatchActor();
};

