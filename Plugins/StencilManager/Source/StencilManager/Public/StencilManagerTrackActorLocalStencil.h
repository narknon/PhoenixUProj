#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffect.h"
#include "StencilManagerTrackActorStencilBase.h"
#include "StencilManagerTrackActorLocalStencil.generated.h"

class ULocalStencilComponentBase;

USTRUCT(BlueprintType)
struct FStencilManagerTrackActorLocalStencil : public FStencilManagerTrackActorStencilBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalStencilEffect DepthFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULocalStencilComponentBase* LocalStencilComponent;
    
    STENCILMANAGER_API FStencilManagerTrackActorLocalStencil();
};

