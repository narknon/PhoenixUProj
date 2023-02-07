#pragma once
#include "CoreMinimal.h"
#include "SkyLightAdvancedParametersOverride.h"
#include "SkyLightBasicParametersOverride.h"
#include "SkyLightDFAOParametersOverride.h"
#include "SkyLightHemisphereParametersOverride.h"
#include "SkyLightShadowParametersOverride.h"
#include "SkyLightLightingParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyLightLightingParametersOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightAdvancedParametersOverride Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightShadowParametersOverride Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightDFAOParametersOverride DFAO;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightHemisphereParametersOverride Hemisphere;
    
    FSkyLightLightingParametersOverride();
};

