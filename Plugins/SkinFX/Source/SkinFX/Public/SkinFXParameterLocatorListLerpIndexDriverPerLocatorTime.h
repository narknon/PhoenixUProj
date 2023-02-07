#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterLocatorListLerpIndexDriver.h"
#include "SkinFXParameterLocatorListLerpIndexDriverPerLocatorTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterLocatorListLerpIndexDriverPerLocatorTime : public USkinFXParameterLocatorListLerpIndexDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerLocatorTimeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerLocatorTimeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSmooth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHermite;
    
    USkinFXParameterLocatorListLerpIndexDriverPerLocatorTime();
};

