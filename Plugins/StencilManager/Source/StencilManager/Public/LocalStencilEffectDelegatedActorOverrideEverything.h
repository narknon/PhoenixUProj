#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectActorOverrideParameters.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectDelegatedActorOverrideEverything.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorOverrideEverything : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalStencilEffectActorOverrideParameters Parameters;
    
    ULocalStencilEffectDelegatedActorOverrideEverything();
};

