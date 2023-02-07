#pragma once
#include "CoreMinimal.h"
#include "SkinFXLocatorListPositionalSource.h"
#include "SkinFXMaterialVectorProperty.h"
#include "SkinFXParameterDriver.h"
#include "SkinFXParameterLocatorListLerpDriver.generated.h"

class USkinFXParameterLocatorListLerpIndexDriver;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXParameterLocatorListLerpDriver : public USkinFXParameterDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialVectorProperty Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkinFXLocatorListPositionalSource> Locators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkinFXParameterLocatorListLerpIndexDriver* LerpIndexDriver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLerpExtraColorsUsingHSV;
    
    USkinFXParameterLocatorListLerpDriver();
};

