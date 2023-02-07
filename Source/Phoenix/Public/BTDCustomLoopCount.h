#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BTDCustomLoopCount.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class UBTDCustomLoopCount : public UObject {
    GENERATED_BODY()
public:
    UBTDCustomLoopCount();
};

