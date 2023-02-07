#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightDirection.h"
#include "DirectionalLightOpposePrimary.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightOpposePrimary : public UDirectionalLightDirection {
    GENERATED_BODY()
public:
    UDirectionalLightOpposePrimary();
};

