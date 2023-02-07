#pragma once
#include "CoreMinimal.h"
#include "SkyLightBasicParameters.h"
#include "SkyLightParams.h"
#include "SkyLightParamsSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsSimple : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParameters Basic;
    
    USkyLightParamsSimple();
};

