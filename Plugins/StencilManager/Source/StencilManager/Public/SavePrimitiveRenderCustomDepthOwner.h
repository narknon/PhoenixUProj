#pragma once
#include "CoreMinimal.h"
#include "SavePrimitiveRenderCustomDepth.h"
#include "SavePrimitiveRenderCustomDepthOwner.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FSavePrimitiveRenderCustomDepthOwner : public FSavePrimitiveRenderCustomDepth {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    FSavePrimitiveRenderCustomDepthOwner();
};

