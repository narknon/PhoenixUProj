#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ELocalStencilBoundsMethod.h"
#include "LocalStencilEffectDelegatedActorOverrideFiltered.h"
#include "LocalStencilEffectDelegatedActorOverrideOverdraw.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULocalStencilEffectDelegatedActorOverrideOverdraw : public ULocalStencilEffectDelegatedActorOverrideFiltered {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshScaleFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MeshInflateBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELocalStencilBoundsMethod BoundsMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_MeshScaleFactor: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_MeshInflateBounds: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_BoundsMethod: 1;
    
    ULocalStencilEffectDelegatedActorOverrideOverdraw();
};

