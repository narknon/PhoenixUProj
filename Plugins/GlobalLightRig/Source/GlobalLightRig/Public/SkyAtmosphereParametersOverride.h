#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereArtDirectionParametersOverride.h"
#include "SkyAtmosphereOverrideDirectionParametersOverride.h"
#include "SkyAtmosphereOzoneParametersOverride.h"
#include "SkyAtmospherePlanetParametersOverride.h"
#include "SkyAtmosphereScatteringParametersOverride.h"
#include "SkyAtmosphereSkyOnlyParametersOverride.h"
#include "SkyAtmosphereParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyAtmosphereParametersOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmospherePlanetParametersOverride Planet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereScatteringParametersOverride Scattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereOzoneParametersOverride Ozone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereArtDirectionParametersOverride ArtDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyParametersOverride SkyOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereOverrideDirectionParametersOverride OverrideDirection;
    
    FSkyAtmosphereParametersOverride();
};

