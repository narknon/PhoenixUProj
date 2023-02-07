#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkyAtmosphereOverrideDirectionParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FSkyAtmosphereOverrideDirectionParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LightDirection0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LightDirection1;
    
    FSkyAtmosphereOverrideDirectionParameters();
};

