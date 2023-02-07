#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CloudLightingParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParams : public UObject {
    GENERATED_BODY()
public:
    UCloudLightingParams();
};

