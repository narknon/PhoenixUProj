#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsNamedCustomBlendDomainLibraryCustom.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsNamedCustomBlendDomainLibraryCustom : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName Name;
    
    URenderSettingsNamedCustomBlendDomainLibraryCustom();
};

