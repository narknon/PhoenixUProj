#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "CameraFadeVegetationDisable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraFadeVegetationDisable : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    UCameraFadeVegetationDisable();
};

