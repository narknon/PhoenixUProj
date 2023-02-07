#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainIf.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainIf : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* B;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* ALessThanB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* AEqualsB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* AGreaterThanB;
    
    URenderSettingsCustomBlendDomainIf();
};

