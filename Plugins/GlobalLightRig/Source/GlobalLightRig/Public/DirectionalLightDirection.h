#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DirectionalLightDirection.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightDirection : public UObject {
    GENERATED_BODY()
public:
    UDirectionalLightDirection();
};

