#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerScalarBlendDomainActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarBlendDomainActor : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UFXAutoTriggerScalarBlendDomainActor();
};

