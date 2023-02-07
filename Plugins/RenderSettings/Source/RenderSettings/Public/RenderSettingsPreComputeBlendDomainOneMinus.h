#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "RenderSettingsPreComputeBlendDomainOneMinus.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsPreComputeBlendDomainOneMinus : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName Name;
    
    URenderSettingsPreComputeBlendDomainOneMinus();
};

