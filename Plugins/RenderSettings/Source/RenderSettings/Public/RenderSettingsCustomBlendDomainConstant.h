#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainConstant : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Constant;
    
    URenderSettingsCustomBlendDomainConstant();
};

