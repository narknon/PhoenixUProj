#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightingCustomBlendablesValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingCustomBlendablesValue : public UObject {
    GENERATED_BODY()
public:
    UGlobalLightingCustomBlendablesValue();
};

