#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsCustomBlendDomainName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FRenderSettingsCustomBlendDomainName();
};

