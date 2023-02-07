#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerUpdateLocalVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateLocalVar : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerUpdateLocalVar();
};

