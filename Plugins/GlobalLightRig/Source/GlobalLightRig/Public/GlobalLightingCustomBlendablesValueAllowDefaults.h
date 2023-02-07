#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendablesValue.h"
#include "GlobalLightingCustomBlendablesValueAllowDefaults.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValueAllowDefaults : public UGlobalLightingCustomBlendablesValue {
    GENERATED_BODY()
public:
    UGlobalLightingCustomBlendablesValueAllowDefaults();
};

