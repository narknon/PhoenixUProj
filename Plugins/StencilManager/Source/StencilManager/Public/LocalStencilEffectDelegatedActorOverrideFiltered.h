#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectDelegatedActorOverride.h"
#include "StencilManagerEffectName.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorOverrideFiltered : public ULocalStencilEffectDelegatedActorOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFilterByEffectName;
    
    ULocalStencilEffectDelegatedActorOverrideFiltered();
};

