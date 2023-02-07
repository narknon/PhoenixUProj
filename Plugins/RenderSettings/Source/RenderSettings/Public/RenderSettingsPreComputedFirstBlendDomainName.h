#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPreComputedBlendDomainNameBase.h"
#include "RenderSettingsPreComputedFirstBlendDomainName.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsPreComputedFirstBlendDomainName : public FRenderSettingsPreComputedBlendDomainNameBase {
    GENERATED_BODY()
public:
    RENDERSETTINGS_API FRenderSettingsPreComputedFirstBlendDomainName();
};

