#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerBoolAllBlendDomainsOne.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolAllBlendDomainsOne : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPreComputedBlendDomainName> BlendDomains;
    
    UFXAutoTriggerBoolAllBlendDomainsOne();
};

