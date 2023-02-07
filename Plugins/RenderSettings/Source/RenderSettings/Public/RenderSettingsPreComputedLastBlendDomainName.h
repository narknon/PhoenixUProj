#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainNameBase.h"
#include "RenderSettingsPreComputedLastBlendDomainName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPreComputedLastBlendDomainName : public FRenderSettingsPreComputedBlendDomainNameBase {
    GENERATED_BODY()
public:
    RENDERSETTINGS_API FRenderSettingsPreComputedLastBlendDomainName();
};

