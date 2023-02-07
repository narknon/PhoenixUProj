#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerScalarBlendDomainPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarBlendDomainPlayer : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UFXAutoTriggerScalarBlendDomainPlayer();
};

