#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LightComponentState.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ULightComponentState : public UObject {
    GENERATED_BODY()
public:
    ULightComponentState();
};

