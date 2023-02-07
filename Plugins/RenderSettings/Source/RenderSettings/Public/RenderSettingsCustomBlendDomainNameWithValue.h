#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "RenderSettingsCustomBlendDomainNameWithValue.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsCustomBlendDomainNameWithValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    RENDERSETTINGS_API FRenderSettingsCustomBlendDomainNameWithValue();
};

