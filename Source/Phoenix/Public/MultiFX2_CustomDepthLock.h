#pragma once
#include "CoreMinimal.h"
#include "StencilValueRenderCustomDepthFilter.h"
#include "MultiFX2_CustomDepthLockBase.h"
#include "MultiFX2_CustomDepthLock.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_CustomDepthLock : public UMultiFX2_CustomDepthLockBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilValueRenderCustomDepthFilter Filter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 StencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRenderCustomDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StencilLockPriority;
    
    UMultiFX2_CustomDepthLock();
};

