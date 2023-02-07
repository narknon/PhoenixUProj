#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsCustomDepth.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsCustomDepth : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERendererStencilMask CustomDepthStencilWriteMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CustomDepthStencilValue;
    
    USpawnByPrimitiveOptionsCustomDepth();
};

