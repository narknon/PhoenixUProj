#pragma once
#include "CoreMinimal.h"
#include "SkyLightLightingParameters.h"
#include "SkyLightParams.h"
#include "SkyLightParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsFull : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightLightingParameters Parameters;
    
    USkyLightParamsFull();
};

