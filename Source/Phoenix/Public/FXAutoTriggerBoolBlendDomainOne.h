#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerBoolBlendDomainOne.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolBlendDomainOne : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UFXAutoTriggerBoolBlendDomainOne();
};

