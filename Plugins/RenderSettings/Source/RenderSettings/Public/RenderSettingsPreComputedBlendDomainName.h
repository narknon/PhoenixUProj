#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainNameBase.h"
#include "RenderSettingsPreComputedBlendDomainName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPreComputedBlendDomainName : public FRenderSettingsPreComputedBlendDomainNameBase {
    GENERATED_BODY()
public:
    RENDERSETTINGS_API FRenderSettingsPreComputedBlendDomainName();
};

