#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectDelegatedForcePlayerCustomDepth.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedForcePlayerCustomDepth : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForcePlayerCustomDepth;
    
    ULocalStencilEffectDelegatedForcePlayerCustomDepth();
};

