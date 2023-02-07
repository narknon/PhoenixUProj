#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterLocatorListLerpIndexDriver.h"
#include "SkinFXParameterLocatorListLerpIndexDriverFixedTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterLocatorListLerpIndexDriverFixedTime : public USkinFXParameterLocatorListLerpIndexDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalLerpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLooped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHermite;
    
    USkinFXParameterLocatorListLerpIndexDriverFixedTime();
};

