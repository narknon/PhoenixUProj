#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainPaused.h"
#include "RenderSettingsCustomBlendDomainPausedSmoothed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainPausedSmoothed : public URenderSettingsCustomBlendDomainPaused {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainPausedSmoothed();
};

