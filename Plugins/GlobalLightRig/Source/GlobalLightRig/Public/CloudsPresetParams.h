#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CloudsPresetParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudsPresetParams : public UObject {
    GENERATED_BODY()
public:
    UCloudsPresetParams();
};

