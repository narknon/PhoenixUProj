#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ExpHeightFogTransmuter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogTransmuter : public UObject {
    GENERATED_BODY()
public:
    UExpHeightFogTransmuter();
};

