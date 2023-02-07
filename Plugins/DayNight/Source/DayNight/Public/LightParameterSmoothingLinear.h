#pragma once
#include "CoreMinimal.h"
#include "LightParameterSmoothing.h"
#include "LightParameterSmoothingLinear.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightParameterSmoothingLinear : public ULightParameterSmoothing {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rate;
    
    ULightParameterSmoothingLinear();
};

