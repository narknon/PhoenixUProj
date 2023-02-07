#pragma once
#include "CoreMinimal.h"
#include "SkyLightDFAOParametersOverride.h"
#include "SkyLightParams.h"
#include "SkyLightParamsOverrideDFAO.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsOverrideDFAO : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightDFAOParametersOverride DFAO;
    
    USkyLightParamsOverrideDFAO();
};

