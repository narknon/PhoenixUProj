#pragma once
#include "CoreMinimal.h"
#include "CloudsWindParams.h"
#include "VolumetricCloudsWindParameters.h"
#include "CloudsWindParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudsWindParamsFull : public UCloudsWindParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWindParameters Parameters;
    
    UCloudsWindParamsFull();
};

