#pragma once
#include "CoreMinimal.h"
#include "StencilManagerMatchActorMovable.h"
#include "StencilManagerMatchActorStationary.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStencilManagerMatchActorStationary : public UStencilManagerMatchActorMovable {
    GENERATED_BODY()
public:
    UStencilManagerMatchActorStationary();
};

