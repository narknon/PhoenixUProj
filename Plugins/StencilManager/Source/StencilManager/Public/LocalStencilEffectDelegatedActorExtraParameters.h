#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectColor.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectScalar.h"
#include "LocalStencilEffectDelegatedActorExtraParameters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorExtraParameters : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectScalar> ExtraScalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectColor> ExtraColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSetExtraScalars: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSetExtraColors: 1;
    
    ULocalStencilEffectDelegatedActorExtraParameters();
};

