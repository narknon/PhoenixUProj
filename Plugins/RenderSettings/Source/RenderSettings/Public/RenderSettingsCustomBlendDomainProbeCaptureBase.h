#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "RenderSettingsCustomBlendDomainProbeCaptureBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainProbeCaptureBase : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainProbeCaptureBase();
};

