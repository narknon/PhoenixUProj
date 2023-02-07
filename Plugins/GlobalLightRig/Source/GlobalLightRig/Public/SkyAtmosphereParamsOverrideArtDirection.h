#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereArtDirectionParametersOverride.h"
#include "SkyAtmosphereParams.h"
#include "SkyAtmosphereParamsOverrideArtDirection.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParamsOverrideArtDirection : public USkyAtmosphereParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereArtDirectionParametersOverride ArtDirection;
    
    USkyAtmosphereParamsOverrideArtDirection();
};

