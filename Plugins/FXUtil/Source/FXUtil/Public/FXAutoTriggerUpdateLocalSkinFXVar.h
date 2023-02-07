#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateLocalVar.h"
#include "FXAutoTriggerUpdateLocalSkinFXVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateLocalSkinFXVar : public UFXAutoTriggerUpdateLocalVar {
    GENERATED_BODY()
public:
    UFXAutoTriggerUpdateLocalSkinFXVar();
};

