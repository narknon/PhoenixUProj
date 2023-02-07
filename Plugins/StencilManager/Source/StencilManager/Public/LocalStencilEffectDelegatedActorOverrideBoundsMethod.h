#pragma once
#include "CoreMinimal.h"
#include "ELocalStencilBoundsMethod.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectDelegatedActorOverrideBoundsMethod.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorOverrideBoundsMethod : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELocalStencilBoundsMethod BoundsMethod;
    
    ULocalStencilEffectDelegatedActorOverrideBoundsMethod();
};

