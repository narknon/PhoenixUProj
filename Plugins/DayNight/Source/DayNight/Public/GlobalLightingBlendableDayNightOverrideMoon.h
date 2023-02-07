#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableDayNightBase.h"
#include "ManualMoonSetup.h"
#include "GlobalLightingBlendableDayNightOverrideMoon.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UGlobalLightingBlendableDayNightOverrideMoon : public UGlobalLightingBlendableDayNightBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FManualMoonSetup Moon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMoonIsSecondaryDirectionalLight;
    
    UGlobalLightingBlendableDayNightOverrideMoon();
};

