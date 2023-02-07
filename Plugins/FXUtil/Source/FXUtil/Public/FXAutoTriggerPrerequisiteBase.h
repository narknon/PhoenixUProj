#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerPrerequisiteBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerPrerequisiteBase : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerPrerequisiteBase();
};

