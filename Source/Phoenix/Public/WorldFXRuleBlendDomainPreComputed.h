#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "WorldFXRuleBlendDomainBase.h"
#include "WorldFXRuleBlendDomainPreComputed.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleBlendDomainPreComputed : public UWorldFXRuleBlendDomainBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UWorldFXRuleBlendDomainPreComputed();
};

