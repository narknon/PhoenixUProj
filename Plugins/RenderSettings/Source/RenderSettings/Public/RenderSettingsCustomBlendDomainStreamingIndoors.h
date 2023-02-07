#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainStreamingIndoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainStreamingIndoors : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainStreamingIndoors();
};

