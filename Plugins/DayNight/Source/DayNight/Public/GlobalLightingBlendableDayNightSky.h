#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableBase.h"
#include "GlobalLightingBlendableDayNightSky.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UGlobalLightingBlendableDayNightSky : public UGlobalLightingBlendableBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableSkySunDisk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableSkyMoonDisk;
    
    UGlobalLightingBlendableDayNightSky();
};

