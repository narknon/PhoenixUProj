#pragma once
#include "CoreMinimal.h"
#include "SkinFXParameterLocatorListLerpIndexDriver.h"
#include "SkinFXParameterLocatorListLerpIndexDriverRandom.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterLocatorListLerpIndexDriverRandom : public USkinFXParameterLocatorListLerpIndexDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTimeBetweenChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTimeBetweenChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSmooth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHermite;
    
    USkinFXParameterLocatorListLerpIndexDriverRandom();
};

