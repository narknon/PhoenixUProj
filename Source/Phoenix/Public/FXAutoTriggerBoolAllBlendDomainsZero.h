#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerBoolAllBlendDomainsZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolAllBlendDomainsZero : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPreComputedBlendDomainName> BlendDomains;
    
    UFXAutoTriggerBoolAllBlendDomainsZero();
};

