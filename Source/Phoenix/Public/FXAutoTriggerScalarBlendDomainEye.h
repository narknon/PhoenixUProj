#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerScalarBlendDomainEye.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarBlendDomainEye : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UFXAutoTriggerScalarBlendDomainEye();
};

