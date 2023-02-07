#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerUpdateBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateBase : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerUpdateBase();
};

