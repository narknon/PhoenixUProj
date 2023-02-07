#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableDayNightBase.h"
#include "ManualMoonSetup.h"
#include "GlobalLightingBlendableDayNightInheritMoon.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UGlobalLightingBlendableDayNightInheritMoon : public UGlobalLightingBlendableDayNightBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FManualMoonSetup Moon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceTimeToMidnight;
    
    UGlobalLightingBlendableDayNightInheritMoon();
};

