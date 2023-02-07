#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainAudioIndoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainAudioIndoors : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainAudioIndoors();
};

