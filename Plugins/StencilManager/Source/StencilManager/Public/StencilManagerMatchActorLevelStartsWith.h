#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActorNameStartsWith.h"
#include "StencilManagerMatchActorLevelStartsWith.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class STENCILMANAGER_API UStencilManagerMatchActorLevelStartsWith : public UStencilManagerMatchActorNameStartsWith {
    GENERATED_BODY()
public:
    UStencilManagerMatchActorLevelStartsWith();
};

