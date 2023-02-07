#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicVarBool.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainPlayerRequirement.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainPlayerRequirement : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool PlayerRequirement;
    
    URenderSettingsCustomBlendDomainPlayerRequirement();
};

