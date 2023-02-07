#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DirectionalLightParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParams : public UObject {
    GENERATED_BODY()
public:
    UDirectionalLightParams();
};

