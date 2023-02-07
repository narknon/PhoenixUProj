#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalLightingBlendableBase.h"
#include "GlobalLightingBlendableBentDirectionalLight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, HideDropdown)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableBentDirectionalLight : public UGlobalLightingBlendableBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuat SunDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunIntensityMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyLightIntensityMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    UGlobalLightingBlendableBentDirectionalLight();
};

