#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SkyLightParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParams : public UObject {
    GENERATED_BODY()
public:
    USkyLightParams();
};

