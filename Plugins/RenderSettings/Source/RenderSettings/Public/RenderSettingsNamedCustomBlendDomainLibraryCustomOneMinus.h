#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsNamedCustomBlendDomainLibraryCustomOneMinus.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsNamedCustomBlendDomainLibraryCustomOneMinus : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName Name;
    
    URenderSettingsNamedCustomBlendDomainLibraryCustomOneMinus();
};

