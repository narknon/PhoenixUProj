#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SkyAtmosphereParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParams : public UObject {
    GENERATED_BODY()
public:
    USkyAtmosphereParams();
};

