#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "RenderSettingsCustomBlendDomainInCinematicCamera.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URenderSettingsCustomBlendDomainInCinematicCamera : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    URenderSettingsCustomBlendDomainInCinematicCamera();
};

