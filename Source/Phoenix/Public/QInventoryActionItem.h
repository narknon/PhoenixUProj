#pragma once
#include "CoreMinimal.h"
#include "QActionItem.h"
#include "QInventoryActionItem.generated.h"

USTRUCT(BlueprintType)
struct FQInventoryActionItem : public FQActionItem {
    GENERATED_BODY()
public:
    PHOENIX_API FQInventoryActionItem();
};

