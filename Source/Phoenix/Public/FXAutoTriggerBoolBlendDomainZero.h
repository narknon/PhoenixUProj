#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "RenderSettingsPreComputedBlendDomainName.h"
#include "FXAutoTriggerBoolBlendDomainZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolBlendDomainZero : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedBlendDomainName BlendDomain;
    
    UFXAutoTriggerBoolBlendDomainZero();
};

