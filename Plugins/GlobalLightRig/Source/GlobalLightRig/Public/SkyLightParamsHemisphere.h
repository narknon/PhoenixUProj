#pragma once
#include "CoreMinimal.h"
#include "SkyLightHemisphereParameters.h"
#include "SkyLightParams.h"
#include "SkyLightParamsHemisphere.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsHemisphere : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightHemisphereParameters Hemisphere;
    
    USkyLightParamsHemisphere();
};

