#pragma once
#include "CoreMinimal.h"
#include "StencilValueRenderCustomDepthFilter.h"
#include "EHighContrastGameplayMarkup.h"
#include "MultiFX2_CustomDepthLockBase.h"
#include "MultiFX2_HighContrastGameplayMarkup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_HighContrastGameplayMarkup : public UMultiFX2_CustomDepthLockBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilValueRenderCustomDepthFilter Filter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHighContrastGameplayMarkup StencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PriorityBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoAdjustForTargeting: 1;
    
    UMultiFX2_HighContrastGameplayMarkup();
};

