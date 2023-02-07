#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkyAtmospherePlanetParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyAtmospherePlanetParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BottomRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AtmosphereHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor GroundAlbedo;
    
    FSkyAtmospherePlanetParameters();
};

