#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainValueStore.h"
#include "RenderSettingsCustomBlendDomainValueOverrides.generated.h"

USTRUCT(BlueprintType)
struct FRenderSettingsCustomBlendDomainValueOverrides : public FRenderSettingsCustomBlendDomainValueStore {
    GENERATED_BODY()
public:
    RENDERSETTINGS_API FRenderSettingsCustomBlendDomainValueOverrides();
};

