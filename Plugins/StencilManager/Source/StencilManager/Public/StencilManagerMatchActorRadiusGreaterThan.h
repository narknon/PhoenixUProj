#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActorBounds.h"
#include "StencilManagerMatchActorRadiusGreaterThan.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerMatchActorRadiusGreaterThan : public UStencilManagerMatchActorBounds {
    GENERATED_BODY()
public:
    UStencilManagerMatchActorRadiusGreaterThan();
};

