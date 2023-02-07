#pragma once
#include "CoreMinimal.h"
#include "SavePrimitiveRenderCustomDepthOwner.h"
#include "SaveAndOverridePrimitiveRenderCustomDepthOwner.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FSaveAndOverridePrimitiveRenderCustomDepthOwner : public FSavePrimitiveRenderCustomDepthOwner {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 StencilValueOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRenderCustomDepthOverride: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverridestencilValue: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverrideRenderCustomDepth: 1;
    
    FSaveAndOverridePrimitiveRenderCustomDepthOwner();
};

