#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereArtDirectionParameters.h"
#include "SkyAtmosphereOverrideDirectionParameters.h"
#include "SkyAtmosphereOzoneParameters.h"
#include "SkyAtmospherePlanetParameters.h"
#include "SkyAtmosphereScatteringParameters.h"
#include "SkyAtmosphereSkyOnlyParameters.h"
#include "SkyAtmosphereParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyAtmosphereParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmospherePlanetParameters Planet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereScatteringParameters Scattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereOzoneParameters Ozone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereArtDirectionParameters ArtDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyParameters SkyOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereOverrideDirectionParameters OverrideDirection;
    
    FSkyAtmosphereParameters();
};

