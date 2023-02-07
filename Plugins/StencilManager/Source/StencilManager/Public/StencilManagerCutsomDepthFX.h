#pragma once
#include "CoreMinimal.h"
#include "StencilRules.h"
#include "StencilManagerCutsomDepthFX.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerCutsomDepthFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 StencilValue;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilRules StencilRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    STENCILMANAGER_API FStencilManagerCutsomDepthFX();
};

