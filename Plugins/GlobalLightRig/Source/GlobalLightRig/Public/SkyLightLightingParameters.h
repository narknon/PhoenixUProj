#pragma once
#include "CoreMinimal.h"
#include "SkyLightAdvancedParameters.h"
#include "SkyLightBasicParameters.h"
#include "SkyLightDFAOParameters.h"
#include "SkyLightHemisphereParameters.h"
#include "SkyLightShadowParameters.h"
#include "SkyLightLightingParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyLightLightingParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParameters Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightAdvancedParameters Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightShadowParameters Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightDFAOParameters DFAO;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightHemisphereParameters Hemisphere;
    
    FSkyLightLightingParameters();
};

