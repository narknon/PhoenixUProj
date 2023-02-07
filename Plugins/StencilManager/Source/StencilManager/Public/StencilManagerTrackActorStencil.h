#pragma once
#include "CoreMinimal.h"
#include "StencilManagerCutsomDepthFX.h"
#include "StencilManagerTrackActorStencilBase.h"
#include "StencilManagerTrackActorStencil.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerTrackActorStencil : public FStencilManagerTrackActorStencilBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerCutsomDepthFX DepthFX;
    
    STENCILMANAGER_API FStencilManagerTrackActorStencil();
};

