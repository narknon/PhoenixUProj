#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocalStencilEffectDelegatedActorOverride.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class STENCILMANAGER_API ULocalStencilEffectDelegatedActorOverride : public UObject {
    GENERATED_BODY()
public:
    ULocalStencilEffectDelegatedActorOverride();
};

