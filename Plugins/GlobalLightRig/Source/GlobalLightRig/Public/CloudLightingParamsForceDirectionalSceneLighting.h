#pragma once
#include "CoreMinimal.h"
#include "CloudLightingParams.h"
#include "CloudLightingParamsForceDirectionalSceneLighting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParamsForceDirectionalSceneLighting : public UCloudLightingParams {
    GENERATED_BODY()
public:
    UCloudLightingParamsForceDirectionalSceneLighting();
};

