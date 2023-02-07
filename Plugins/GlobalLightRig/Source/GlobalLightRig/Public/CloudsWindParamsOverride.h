#pragma once
#include "CoreMinimal.h"
#include "CloudsWindParams.h"
#include "VolumetricCloudsWindParametersOverride.h"
#include "CloudsWindParamsOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudsWindParamsOverride : public UCloudsWindParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWindParametersOverride Parameters;
    
    UCloudsWindParamsOverride();
};

