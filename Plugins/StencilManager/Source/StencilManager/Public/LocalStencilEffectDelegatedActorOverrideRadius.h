#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectDelegatedActorOverrideRadius.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorOverrideRadius : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutlineRadius;
    
    ULocalStencilEffectDelegatedActorOverrideRadius();
};

