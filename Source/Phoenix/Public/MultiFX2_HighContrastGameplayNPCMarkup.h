#pragma once
#include "CoreMinimal.h"
#include "StencilValueRenderCustomDepthFilter.h"
#include "MultiFX2_CustomDepthLockBase.h"
#include "MultiFX2_HighContrastGameplayNPCMarkup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_HighContrastGameplayNPCMarkup : public UMultiFX2_CustomDepthLockBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilValueRenderCustomDepthFilter Filter;
    
    UMultiFX2_HighContrastGameplayNPCMarkup();
};

