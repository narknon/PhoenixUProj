#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainNameBase.h"
#include "RenderSettingsPreComputedNormalBlendDomainName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPreComputedNormalBlendDomainName : public FRenderSettingsPreComputedBlendDomainNameBase {
    GENERATED_BODY()
public:
    RENDERSETTINGS_API FRenderSettingsPreComputedNormalBlendDomainName();
};

