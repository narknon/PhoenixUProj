#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereParameters.h"
#include "SkyAtmosphereParams.h"
#include "SkyAtmosphereParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParamsFull : public USkyAtmosphereParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereParameters Parameters;
    
    USkyAtmosphereParamsFull();
};

