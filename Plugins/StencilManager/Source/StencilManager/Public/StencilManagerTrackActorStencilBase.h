#pragma once
#include "CoreMinimal.h"
#include "SavePrimitiveRenderCustomDepth.h"
#include "StencilManagerTrackActor.h"
#include "StencilManagerTrackActorStencilBase.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FStencilManagerTrackActorStencilBase : public FStencilManagerTrackActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UPrimitiveComponent>, FSavePrimitiveRenderCustomDepth> OriginalValues;
    
    STENCILMANAGER_API FStencilManagerTrackActorStencilBase();
};

