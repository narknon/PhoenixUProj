#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicBoolResult.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainPlayerResult.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainPlayerResult : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicBoolResult PlayerResult;
    
    URenderSettingsCustomBlendDomainPlayerResult();
};

