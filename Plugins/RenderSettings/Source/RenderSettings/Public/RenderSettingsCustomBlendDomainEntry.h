#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedLastBlendDomainName.h"
#include "RenderSettingsCustomBlendDomainEntry.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FRenderSettingsCustomBlendDomainEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName domain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPreComputedLastBlendDomainName DefaultValueBlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertDefaultValueBlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDefaultValueBlendDomain;
    
    FRenderSettingsCustomBlendDomainEntry();
};

