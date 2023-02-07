#pragma once
#include "CoreMinimal.h"
#include "EDayNightInheritSunMode.h"
#include "GlobalLightingBlendableDayNightBase.h"
#include "GlobalLightingBlendableDayNightInheritSun.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UGlobalLightingBlendableDayNightInheritSun : public UGlobalLightingBlendableDayNightBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightInheritSunMode Mode;
    
    UGlobalLightingBlendableDayNightInheritSun();
};

