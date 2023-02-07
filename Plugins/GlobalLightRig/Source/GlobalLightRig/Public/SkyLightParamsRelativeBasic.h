#pragma once
#include "CoreMinimal.h"
#include "SkyLightBasicParametersRelative.h"
#include "SkyLightParams.h"
#include "SkyLightParamsRelativeBasic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsRelativeBasic : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParametersRelative Basic;
    
    USkyLightParamsRelativeBasic();
};

