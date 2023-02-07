#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomains.generated.h"

class URenderSettingsCustomBlendDomainBase;

USTRUCT(BlueprintType)
struct FRenderSettingsCustomBlendDomains {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomainBase*> AllDomains;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomainBase*> PreComputeDomainsFirst;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomainBase*> PreComputeDomainsNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomainBase*> PreComputeDomainsLast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomainBase*> PreComputeDomainsCustom;
    
    RENDERSETTINGS_API FRenderSettingsCustomBlendDomains();
};

