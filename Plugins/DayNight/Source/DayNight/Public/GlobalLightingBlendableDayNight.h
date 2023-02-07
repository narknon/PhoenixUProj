#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableDayNightBase.h"
#include "GlobalLightingBlendableDayNight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UGlobalLightingBlendableDayNight : public UGlobalLightingBlendableDayNightBase {
    GENERATED_BODY()
public:
    UGlobalLightingBlendableDayNight();
};

