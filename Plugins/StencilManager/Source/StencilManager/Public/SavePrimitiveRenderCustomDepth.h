#pragma once
#include "CoreMinimal.h"
#include "SavePrimitiveRenderCustomDepth.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FSavePrimitiveRenderCustomDepth {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 StencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRenderCustomDepth: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bManageVisibility: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bVisible: 1;
    
    FSavePrimitiveRenderCustomDepth();
};

