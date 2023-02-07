#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerActorHasTag.h"
#include "FXAutoTriggerActorNotHasTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerActorNotHasTag : public UFXAutoTriggerActorHasTag {
    GENERATED_BODY()
public:
    UFXAutoTriggerActorNotHasTag();
};

