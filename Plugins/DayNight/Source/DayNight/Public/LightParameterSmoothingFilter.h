#pragma once
#include "CoreMinimal.h"
#include "LightParameterSmoothing.h"
#include "LightParameterSmoothingFilter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightParameterSmoothingFilter : public ULightParameterSmoothing {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeConstant;
    
    ULightParameterSmoothingFilter();
};

