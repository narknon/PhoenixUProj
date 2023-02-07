#pragma once
#include "CoreMinimal.h"
#include "StencilManagerTrackActor.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerTrackActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Effect;
    
    STENCILMANAGER_API FStencilManagerTrackActor();
};

