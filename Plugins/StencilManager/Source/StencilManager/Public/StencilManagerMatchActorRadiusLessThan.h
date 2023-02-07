#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActorBounds.h"
#include "StencilManagerMatchActorRadiusLessThan.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerMatchActorRadiusLessThan : public UStencilManagerMatchActorBounds {
    GENERATED_BODY()
public:
    UStencilManagerMatchActorRadiusLessThan();
};

